/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:25:04 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:29:16 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	y = ligne
	x = colones
*/

void	bottom_checking(t_map *map)
{
	t_coord	pos;

	pos.y = 0;
	while (pos.y < map->coord.y)
	{
		pos.x = 0;
		while (pos.x < map->coord.x)
		{
			if (map->map[pos.y][pos.x] == 'P')
				fill(map, pos);
			pos.x++;
		}
		while (pos.x >= 0)
		{
			if (map->map[pos.y][pos.x] == 'P')
				fill(map, pos);
			pos.x--;
		}
		pos.y++;
	}
}

int	check_wall(t_map *map)
{
	t_coord	pos;

	pos.y = 0;
	pos.x = 0;
	while (pos.y < map->coord.y - 1 && map->map[pos.y])
	{
		if (map->map[pos.y++][0] != '1')
			return (0);
	}
	while (pos.x < map->coord.x && map->map[0][pos.x])
	{
		if (map->map[0][pos.x++] != '1')
			return (0);
	}
	while (pos.y-- > 0 && map->map[pos.y])
	{
		if (map->map[pos.y][map->coord.x - 1] != '1')
			return (0);
	}
	while (pos.x-- > 0 && map->map[map->coord.y - 1][pos.x])
	{
		if (map->map[map->coord.y - 1][pos.x] != '1')
			return (0);
	}
	return (1);
}

int	check_elem(t_map *map)
{
	int		c_count;
	int		p_count;
	int		e_count;
	t_coord	pos;

	c_count = 0;
	p_count = 0;
	e_count = 0;
	pos.y = 0;
	while (pos.y < map->coord.y)
	{
		if (check_elem_loop(map, &p_count, &c_count, pos.y++))
			e_count++;
	}
	map->collectible_tot = c_count;
	map->collectible_cnt = 0;
	if (c_count > 0 && p_count == 1 && e_count == 1)
		return (1);
	return (0);
}

void	top_checking(t_map *map)
{
	t_coord	pos;

	pos.y = map->coord.y - 1;
	while (pos.y > 0)
	{
		pos.x = 0;
		while (pos.x < map->coord.x)
		{
			if (map->map[pos.y][pos.x] == 'P')
				fill(map, pos);
			pos.x++;
		}
		while (pos.x >= 0)
		{
			if (map->map[pos.y][pos.x] == 'P')
				fill(map, pos);
			pos.x--;
		}
		pos.y--;
	}
	bottom_checking(map);
}

int	cross_check(t_map *map)
{
	t_coord	dest;
	t_coord	pos;
	int		i;

	i = 0;
	if (!check_wall(map) || !check_elem(map))
		return (0);
	dest = get_exit_coord(map);
	while (i < 2)
		(top_checking(map), i++);
	pos.y = 0;
	while (pos.y < map->coord.y)
	{
		if (!cross_check_loop(map, pos.y++))
			return (0);
	}
	return (check_arround(map, dest));
}
