/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:28:10 by itahri            #+#    #+#             */
/*   Updated: 2024/07/02 17:57:12 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_tile(t_mlx_data *data, t_coord pos)
{
	if (data->map->map[pos.y][pos.x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_face_img, pos.x * 64, pos.y * 64);
	else if (data->map->map[pos.y][pos.x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
	else if (data->map->map[pos.y][pos.x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tree_img,
			pos.x * 64, pos.y * 64);
	else if (data->map->map[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collectible_img, pos.x * 64, pos.y * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
}

void	render_map(t_mlx_data *data)
{
	t_coord	pos;

	pos.y = 0;
	while (pos.y < data->map->coord.y)
	{
		pos.x = 0;
		while (pos.x < data->map->coord.x)
		{
			render_tile(data, pos);
			pos.x++;
		}
		pos.y++;
	}
}

int	check_collectible_cnt(t_mlx_data *data)
{
	if (data->map->collectible_cnt == data->map->collectible_tot)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_img,
			data->map->exit_pos.x * 64, data->map->exit_pos.y * 64);
		return (1);
	}
	return (0);
}

void	check_exit(t_mlx_data *data)
{
	t_coord	p_pos;
	t_coord	e_pos;

	p_pos = data->map->player_pos;
	e_pos = data->map->exit_pos;
	if (p_pos.x == e_pos.x && p_pos.y == e_pos.y
		&& data->map->collectible_cnt == data->map->collectible_tot)
		escape_input(data);
}
