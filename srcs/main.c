/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:30:30 by itahri            #+#    #+#             */
/*   Updated: 2024/07/02 21:17:57 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char const *argv[])
{
	t_map		  *map;
	t_map		  *buffer;
	t_mlx_data	  *data;

	if (argc != 2)
		return (ft_printf("Invalid arguments."), -1);
	buffer = map_formating(argv);
	ft_printf("ligne : %d, colones : %d\n", buffer->coord.y, buffer->coord.x);
	int i = 0;
	while (i < buffer->coord.y)
		ft_printf("%s\n", buffer->map[i++]);
	if (cross_check(buffer))
		ft_printf("collectible : %d \nmap correct\n", buffer->collectible_cnt);
	else
		ft_printf("map incorrect\n");
	i = 0;
	while (i < buffer->coord.y)
		ft_printf("%s\n", buffer->map[i++]);
	free_map(buffer);
	map = map_formating(argv);
	if (!map)
		return (-1);
	check_elem(map);
	ft_printf("map formating success\n");
	data = create_window(map);
	if (!data)
		return (-1);
	ft_printf("windows create with success\n");
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, EXIT_CROSS, 0, escape_input, data);
	render_map(data);
	mlx_loop(data->mlx_ptr);
	return 0;
}
