/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:21:36 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:27:59 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	second_case(t_map *map, t_coord pos)
{
	int	cnt;

	cnt = 0;
	if (map->map[pos.y][pos.x - 1] != '1' && map->map[pos.y][pos.x - 1] != 'E'
		&& map->map[pos.y][pos.x - 1] != 'C')
		map->map[pos.y][pos.x - 1] = 'P';
	else
		cnt++;
	if (map->map[pos.y - 1][pos.x] != '1' && map->map[pos.y - 1][pos.x] != 'E'
		&& map->map[pos.y - 1][pos.x] != 'C')
		map->map[pos.y - 1][pos.x] = 'P';
	else
		cnt++;
	return (cnt);
}

int	fill(t_map *map, t_coord pos)
{
	int	w_count;

	w_count = 0;
	if (pos.x < map->coord.x && pos.y < map->coord.y)
	{
		if (map->map[pos.y + 1][pos.x] != '1' && map->map[pos.y
			+ 1][pos.x] != 'E' && map->map[pos.y + 1][pos.x] != 'C')
			map->map[pos.y + 1][pos.x] = 'P';
		else
			w_count++;
		if (map->map[pos.y][pos.x + 1] != '1' && map->map[pos.y][pos.x
			+ 1] != 'E' && map->map[pos.y][pos.x + 1] != 'C')
			map->map[pos.y][pos.x + 1] = 'P';
		else
			w_count++;
	}
	if (pos.y > 0 && pos.x > 0)
		w_count += second_case(map, pos);
	if (w_count == 4)
		return (0);
	else
		return (1);
}

int	check_arround(t_map *map, t_coord pos)
{
	int	ok;

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

int	check_elem_loop(t_map *map, int *p_count, int *c_count, int y)
{
	t_coord	pos;
	int		exit;

	pos.x = 0;
	pos.y = y;
	exit = 0;
	while (pos.x < map->coord.x)
	{
		if (map->map[pos.y][pos.x] == 'C')
			*c_count += 1;
		else if (map->map[pos.y][pos.x] == 'P')
		{
			map->player_pos = pos;
			*p_count += 1;
		}
		else if (map->map[pos.y][pos.x] == 'E')
		{
			map->exit_pos = pos;
			exit++;
		}
		pos.x++;
	}
	return (exit);
}
