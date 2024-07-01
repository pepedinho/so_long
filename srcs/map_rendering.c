/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:28:10 by itahri            #+#    #+#             */
/*   Updated: 2024/07/01 13:46:27 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void  render_map(t_mlx_data *data)
{
	t_coord	pos;

	pos.y = 0;
	if (!data->map->map)
		(ft_printf("scope error\n"), exit(EXIT_FAILURE));
	while (pos.y < data->map->coord.y)
	{
		pos.x = 0;
		while (pos.x < data->map->coord.x)
		{
			if (data->map->map[pos.y][pos.x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprite_face_img, pos.x * 64, pos.y * 64);
			else if (data->map->map[pos.y][pos.x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64, pos.y * 64);
			else if (data->map->map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tree_img, pos.x * 64, pos.y * 64);
			else 
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img, pos.x * 64, pos.y * 64);
			pos.x++;
		}
		pos.y++;
	}
}
