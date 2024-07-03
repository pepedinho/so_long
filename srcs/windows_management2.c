/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_management2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:41:14 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:55:25 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_img_sec(t_mlx_data *data)
{
	int	img_width;
	int	img_height;

	img_width = WIDTH;
	img_height = HEIGHT;
	data->sprite_left_img = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_LEFT,
			&img_width, &img_height);
	if (!data->sprite_left_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->sprite_right_img = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_RIGHT,
			&img_width, &img_height);
	if (!data->sprite_right_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE,
			&img_width, &img_height);
	if (!data->collectible_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_SPRITE,
			&img_width, &img_height);
	if (!data->exit_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	return (1);
}

int	escape_input(t_mlx_data *data)
{
	free_img(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_map(data->map);
	free(data);
	exit(EXIT_SUCCESS);
	return (1);
}
