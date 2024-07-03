/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:30:30 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 18:40:36 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char const *argv[])
{
	t_map		*map;
	t_map		*buffer;
	t_mlx_data	*data;

	if (argc != 2)
		return (ft_printf("Error Invalid arguments."), -1);
	buffer = map_formating(argv);
	if (!cross_check(buffer))
		return (free_map(buffer), ft_printf("Error map incorrect!\n"), -1);
	free_map(buffer);
	map = map_formating(argv);
	if (!map)
		return (-1);
	check_elem(map);
	data = create_window(map);
	if (!data)
		return (-1);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, EXIT_CROSS, 0, escape_input, data);
	render_map(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
