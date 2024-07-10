/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:05:09 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:55:43 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <X11/keysym.h>

int	init_img(t_mlx_data *data)
{
	int	img_width;
	int	img_height;

	img_width = WIDTH;
	img_height = HEIGHT;
	data->tree_img = mlx_xpm_file_to_image(data->mlx_ptr, TREE, &img_width,
			&img_height);
	if (!data->tree_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &img_width,
			&img_height);
	if (!data->floor_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->sprite_back_img = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_BACK,
			&img_width, &img_height);
	if (!data->sprite_back_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	data->sprite_face_img = mlx_xpm_file_to_image(data->mlx_ptr, SPRITE_FACE,
			&img_width, &img_height);
	if (!data->sprite_face_img || img_width != WIDTH || img_height != HEIGHT)
		return (ft_printf("Error with image loading\n"), escape_input(data), 0);
	init_img_sec(data);
	return (1);
}

void	img_to_null(t_mlx_data *data)
{
	data->floor_img = NULL;
	data->tree_img = NULL;
	data->sprite_face_img = NULL;
	data->sprite_back_img = NULL;
	data->sprite_right_img = NULL;
	data->sprite_left_img = NULL;
	data->collectible_img = NULL;
	data->exit_img = NULL;
}

t_mlx_data	*create_window(t_map *map)
{
	t_mlx_data	*data;

	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, map->coord.x * 64,
			map->coord.y * 64, "TEST");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (NULL);
	}
	img_to_null(data);
	if (!init_img(data))
		return (NULL);
	data->map = map;
	return (data);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	static int	cnt;

	if (keysym == XK_Escape)
		escape_input(data);
	else if (keysym == D_KEY)
		(ft_printf("moove count : %d\n", ++cnt), moove_right(data));
	else if (keysym == A_KEY)
		(ft_printf("moove count : %d\n", ++cnt), moove_left(data));
	else if (keysym == W_KEY)
		(ft_printf("moove count : %d\n", ++cnt), moove_top(data));
	else if (keysym == S_KEY)
		(ft_printf("moove count : %d\n", ++cnt), moove_bottom(data));
	check_collectible_cnt(data);
	check_exit(data);
	return (1);
}

void	free_img(t_mlx_data *data)
{
	if (data->floor_img)
		mlx_destroy_image(data->mlx_ptr, data->floor_img);
	if (data->sprite_back_img)
		mlx_destroy_image(data->mlx_ptr, data->sprite_back_img);
	if (data->sprite_face_img)
		mlx_destroy_image(data->mlx_ptr, data->sprite_face_img);
	if (data->sprite_left_img)
		mlx_destroy_image(data->mlx_ptr, data->sprite_left_img);
	if (data->sprite_right_img)
		mlx_destroy_image(data->mlx_ptr, data->sprite_right_img);
	if (data->tree_img)
		mlx_destroy_image(data->mlx_ptr, data->tree_img);
	if (data->collectible_img)
		mlx_destroy_image(data->mlx_ptr, data->collectible_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->exit_img);
}
