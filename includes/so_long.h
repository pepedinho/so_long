/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:14:45 by itahri            #+#    #+#             */
/*   Updated: 2024/06/25 19:20:12 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_map
{
	char			**map;
	struct s_coord	coord;
}					t_map;


//map parsing
t_coord	file_len(const char** argv);
t_map	*map_allocation(const char** argv);
t_map	*map_formating(const char **argv);
void	free_map(t_map *map);

#endif