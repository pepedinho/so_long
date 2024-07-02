/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:45:23 by itahri            #+#    #+#             */
/*   Updated: 2024/07/02 15:55:55 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void  moove_right(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y ][data->map->player_pos.x + 1] != '1')
	{
		data->map->player_pos.x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64 , pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_right_img, (pos.x + 1) * 64 , pos.y * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_right_img, pos.x * 64 , pos.y * 64);
}

void  moove_left(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y ][data->map->player_pos.x - 1] != '1')
	{
		data->map->player_pos.x--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64 , pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_left_img, (pos.x - 1) * 64 , pos.y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_left_img, pos.x * 64 , pos.y * 64);
	}
}

void  moove_top(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y - 1][data->map->player_pos.x] != '1')
	{
		data->map->player_pos.y--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64 , pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_back_img, pos.x * 64 , (pos.y - 1) * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_back_img, pos.x * 64 , pos.y * 64);
}

void  moove_bottom(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y + 1][data->map->player_pos.x] != '1')
	{
		data->map->player_pos.y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64 , pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_face_img, pos.x * 64 , (pos.y + 1) * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_face_img, pos.x * 64 , pos.y * 64);
}
