/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:32:13 by itahri            #+#    #+#             */
/*   Updated: 2024/06/26 18:41:01 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coord	file_len(const char** argv)
{
	int		map;
	char	buffer[100];
	int		nb_read;
	int		i;
	t_coord	pos;

	map = open(argv[1], O_RDONLY);
	nb_read = -1;
	pos.y = 0;
	pos.x = 0;
	while (nb_read != 0)
	{
		nb_read = read(map, buffer, 100);
		if (nb_read == -1)
			exit(EXIT_FAILURE);
		i = 0;
		while (i < nb_read && buffer[i])
		{
			if (buffer[i] == '\n')
			{
				if (pos.y == 0)
					pos.x = i;
				while (buffer[i] == '\n')
					i++;
				pos.y++;
			}
			i++;
		}
	}
	return (close(map), pos);
}


t_map	*map_allocation(const char **argv)
{
	t_map	*map;
	t_coord	pos;
	char	**buffer;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	pos = file_len(argv);
	buffer = malloc(sizeof(char *) * (pos.y + 1));
	if (!buffer)
		return (free(map), NULL);
	i = 0;
	while (i < pos.y)
	{
		buffer[i] = malloc(sizeof(char) * (pos.x + 1));
		if (!buffer[i])
		{
			while (i-- != 0)
				free(buffer[i]);
			free (buffer);
		}
		i++;
	}
	buffer[i] = NULL;
	map->coord = pos;
	map->map = buffer;
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->coord.y)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

t_map	*map_formating(const char **argv)
{
	t_map	*map;
	char	*buffer;
	t_coord	index;
	int		k;
	int		fd;

	map = map_allocation(argv);
	if (!map)
		return (NULL);
	buffer = ft_calloc(sizeof(char), ((map->coord.x * map->coord.y) + map->coord.y + 1));
	if (!buffer)
		return (free_map(map), NULL);
	fd = open(argv[1], O_RDONLY);
	index.y = read(fd, buffer, (map->coord.x * map->coord.y) + map->coord.y);
	if (index.y == -1)
		return (0);
	index.y = 0;
	k = 0;
	while (index.y < map->coord.y)
	{
		index.x = 0;
		while (index.x < map->coord.x && buffer[k] != '\n')
			map->map[index.y][index.x++] = buffer[k++];
		while (buffer[k] == '\n')
			k++;
		map->map[index.y][index.x] = '\0';
		index.y++;
	}
	return (close(fd), free(buffer), map);
}
