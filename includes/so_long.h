/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:14:45 by itahri            #+#    #+#             */
/*   Updated: 2024/06/29 16:49:21 by itahri           ###   ########.fr       */
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
	int				collectible_cnt;
}					t_map;

typedef struct s_mlx_data
{
	void	  *mlx_ptr;
	void	  *win_ptr;
}			  t_mlx_data;

//map parsing
t_coord	file_len(const char** argv);
t_map	*map_allocation(const char** argv);
t_map	*map_formating(const char **argv);
void	free_map(t_map *map);

// map validity check
int	cross_check(t_map *map);

// windows managements
t_mlx_data	*create_window(void);

//input_event

int	handle_input(int keysym, t_mlx_data *data);
int	escape_input(t_mlx_data *data);

#endif
