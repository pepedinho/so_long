/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:45:23 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:35:33 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moove_right(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y][data->map->player_pos.x
		+ 1] != '1')
	{
		if (data->map->map[pos.y][pos.x + 1] == 'C')
		{
			data->map->map[pos.y][pos.x + 1] = '0';
			data->map->collectible_cnt++;
		}
		data->map->player_pos.x++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_right_img, (pos.x + 1) * 64, pos.y * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_right_img, pos.x * 64, pos.y * 64);
}

void	moove_left(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y][data->map->player_pos.x
		- 1] != '1')
	{
		if (data->map->map[pos.y][pos.x - 1] == 'C')
		{
			data->map->map[pos.y][pos.x - 1] = '0';
			data->map->collectible_cnt++;
		}
		data->map->player_pos.x--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_left_img, (pos.x - 1) * 64, pos.y * 64);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_left_img, pos.x * 64, pos.y * 64);
	}
}

void	moove_top(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y - 1]
		[data->map->player_pos.x] != '1')
	{
		if (data->map->map[pos.y - 1][pos.x] == 'C')
		{
			data->map->map[pos.y - 1][pos.x] = '0';
			data->map->collectible_cnt++;
		}
		data->map->player_pos.y--;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_back_img, pos.x * 64, (pos.y - 1) * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_back_img, pos.x * 64, pos.y * 64);
}

void	moove_bottom(t_mlx_data *data)
{
	t_coord	pos;

	pos = data->map->player_pos;
	if (data->map->map[data->map->player_pos.y + 1]
		[data->map->player_pos.x] != '1')
	{
		if (data->map->map[pos.y + 1][pos.x] == 'C')
		{
			data->map->map[pos.y + 1][pos.x] = '0';
			data->map->collectible_cnt++;
		}
		data->map->player_pos.y++;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img,
			pos.x * 64, pos.y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_face_img, pos.x * 64, (pos.y + 1) * 64);
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprite_face_img, pos.x * 64, pos.y * 64);
}
