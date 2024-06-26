/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:25:04 by itahri            #+#    #+#             */
/*   Updated: 2024/06/26 18:22:16 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	y = ligne
	x = colones
*/

int	fill(t_map *map, t_coord pos)
{
	int w_count;

	w_count = 0;
	if (pos.x < map->coord.x && pos.y < map->coord.y)
	{
		if (map->map[pos.y + 1][pos.x] != '1' && map->map[pos.y + 1][pos.x] != 'E')
			map->map[pos.y + 1][pos.x] = 'P';
		else
			w_count++;
		if (map->map[pos.y][pos.x + 1] != '1' && map->map[pos.y][pos.x + 1] != 'E')
			map->map[pos.y][pos.x + 1] = 'P';
		else
			w_count++;
	}
	if (pos.y > 0 && pos.x > 0)
	{
		if (map->map[pos.y][pos.x - 1] != '1' && map->map[pos.y][pos.x - 1] != 'E')
			map->map[pos.y][pos.x - 1] = 'P';
		else
			w_count++;
		if (map->map[pos.y - 1][pos.x] != '1' && map->map[pos.y - 1][pos.x] != 'E')
			map->map[pos.y - 1][pos.x] = 'P';
		else
			w_count++;
	}
	if (w_count == 4)
		return (0);
	else
		return (1);
}

int	check_arround(t_map *map, t_coord pos)
{
	int ok;

	ok = 0;
	if (pos.x > 0 && pos.y > 0)
	{
		if (map->map[pos.y - 1][pos.x] == 'P')
			ok = 1;
		if (map->map[pos.y][pos.x - 1] == 'P')
			ok = 1;
	}
	if (pos.x < map->coord.x && pos.y < map->coord.y)
	{
		if (map->map[pos.y + 1][pos.x] == 'P')
			ok = 1;
		if (map->map[pos.y][pos.x + 1] == 'P')
			ok = 1;
	}
	return (ok);
}

t_coord	get_exit_coord(t_map *map)
{
	t_coord	pos;

	pos.y = 0;
	while (pos.y < map->coord.y)
	{
		pos.x = 0;
		while (pos.x < map->coord.x)
		{
			if (map->map[pos.y][pos.x] == 'E')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (((t_coord){0, 0}));
}

void  bottom_checking(t_map *map)
{
	t_coord	pos;


	pos.y = 0;
	while (pos.y < map->coord.y)
	{
		pos.x = 0;
		while (pos.x < map->coord.x)
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				if (!fill(map, pos))
					ft_printf("ERROR\n");
			}
			pos.x++;
		}
		while (pos.x >= 0)
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				if (!fill(map, pos))
					ft_printf("ERROR\n");
			}
			pos.x--;
		}
		pos.y++;
	}
}

void top_checking(t_map *map)
{
	t_coord	pos;

	pos.y = map->coord.y - 1;
	ft_printf("[2] begin y : %d\n", pos.y);
	while (pos.y > 0)
	{
		pos.x = 0;
		while (pos.x < map->coord.x)
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				if (!fill(map, pos))
					ft_printf("ERROR\n");
			}
			pos.x++;
		}
		while (pos.x >= 0)
		{
			if (map->map[pos.y][pos.x] == 'P')
			{
				if (!fill(map, pos))
					ft_printf("ERROR\n");
			}
			pos.x--;
		}
		pos.y--;
	}
	bottom_checking(map);
}

int	cross_check(t_map *map)
{
	t_coord	dest;
	int		i;

	i = 0;
	dest = get_exit_coord(map);
	while (i < 2)
	{
		top_checking(map);
		i++;
	}
	return (check_arround(map, dest));
}
