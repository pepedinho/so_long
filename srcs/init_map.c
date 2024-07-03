/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:38:19 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:26:39 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map(t_map *map, char **buffer, t_coord pos, int i)
{
	buffer[i] = NULL;
	map->coord = pos;
	map->map = buffer;
	map->player_pos.y = -1;
	map->player_pos.x = -1;
	map->exit_pos.x = -1;
	map->exit_pos.y = -1;
}

void	formating(t_map *map, char *buffer)
{
	int		k;
	t_coord	index;

	k = 0;
	index.y = 0;
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
}

int	cross_check_loop(t_map *map, int y)
{
	t_coord	pos;

	pos.y = y;
	pos.x = 0;
	while (pos.x < map->coord.x)
	{
		if (map->map[pos.y][pos.x] == 'C')
		{
			if (!check_arround(map, pos))
				return (0);
		}
		pos.x++;
	}
	return (1);
}
