/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:30:30 by itahri            #+#    #+#             */
/*   Updated: 2024/06/26 15:03:18 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char const *argv[])
{
	t_map	*map;

	(void)argv;
	if (argc != 2)
		return (ft_printf("Invalid arguments."), -1);

	map = map_formating(argv);
	ft_printf("ligne : %d, colones : %d\n", map->coord.y, map->coord.x);
	int i = 0;
	while (i < map->coord.y)
		ft_printf("%s\n", map->map[i++]);
	if (cross_check(map))
		ft_printf("collectible : %d \nmap correct\n", map->collectible_cnt);
	else
		ft_printf("map incorrect\n");
	i = 0;
	while (i < map->coord.y)
		ft_printf("%s\n", map->map[i++]);

	free_map(map);
	return 0;
}
