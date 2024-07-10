/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:32:13 by itahri            #+#    #+#             */
/*   Updated: 2024/07/10 14:46:38 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	pos_increment(char *buffer, t_coord *pos, int i)
{
	if (buffer[i] == '\n')
	{
		if (pos->y == 0)
			pos->x = i;
		if (buffer[i + 1] == '\n')
			return (0);
		pos->y++;
	}
	return (1);
}

t_coord	file_len(const char **argv)
{
	int		map;
	char	buffer[100];
	int		nb_read;
	int		i;
	t_coord	pos;

	map = open(argv[1], O_RDONLY);
	if (map == -1)
		(ft_printf("Error '%s' dont exist!\n", argv[1]), exit(EXIT_FAILURE));
	nb_read = -1;
	pos.y = 0;
	pos.x = 0;
	while (nb_read != 0)
	{
		nb_read = read(map, buffer, 100);
		if (nb_read == -1)
			(close(map), exit(EXIT_FAILURE));
		i = 0;
		while (i < nb_read && buffer[i])
		{
			if (!pos_increment(buffer, &pos, i++))
				(close(map), ft_printf("Error incorrect map!"),
					exit(EXIT_FAILURE));
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

	pos = file_len(argv);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	buffer = malloc(sizeof(char *) * (pos.y + 1));
	if (!buffer)
		return (free(map), NULL);
	i = 0;
	while (i < pos.y)
	{
		buffer[i] = malloc(sizeof(char) * (pos.x + 1));
		if (!buffer[i])
		{
			while (i-- >= 0)
				free(buffer[i]);
			(free(buffer), free(map), exit(EXIT_FAILURE));
		}
		i++;
	}
	return (init_map(map, buffer, pos, i), map);
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
	int		fd;
	int		nb_read;

	map = map_allocation(argv);
	if (!map)
		return (NULL);
	buffer = ft_calloc(sizeof(char), ((map->coord.x * map->coord.y)
				+ map->coord.y + 1));
	if (!buffer)
		return (free_map(map), NULL);
	fd = open(argv[1], O_RDONLY);
	nb_read = read(fd, buffer, (map->coord.x * map->coord.y) + map->coord.y);
	if (nb_read == -1)
		return (NULL);
	formating(map, buffer);
	return (close(fd), free(buffer), map);
}
