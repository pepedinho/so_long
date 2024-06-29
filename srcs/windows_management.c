/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <ithari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:05:09 by itahri            #+#    #+#             */
/*   Updated: 2024/06/29 16:55:49 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <X11/keysym.h>

t_mlx_data  *create_window(void)
{
	t_mlx_data *data;	
	
	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 400, 400, "TEST");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (NULL);
	}
	return (data);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
		escape_input(data);
	ft_printf("the key: [%d] has been pressed\n", keysym);
	return (1);
}

int	escape_input(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(1);
	return (1);
}
