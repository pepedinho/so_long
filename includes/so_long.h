/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:14:45 by itahri            #+#    #+#             */
/*   Updated: 2024/07/03 20:56:01 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define WIDTH 64
# define HEIGHT 64

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define EXIT_CROSS 17

# define FLOOR "assets/floor.xpm"
# define SPRITE_BACK "assets/sprite_back.xpm"
# define SPRITE_FACE "assets/sprite_face.xpm"
# define SPRITE_RIGHT "assets/sprite_right.xpm"
# define SPRITE_LEFT "assets/sprite_left.xpm"
# define TREE "assets/tree.xpm"
# define COLLECTIBLE "assets/master_ball.xpm"
# define EXIT_SPRITE "assets/exit.xpm"

typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct s_map
{
	char			**map;
	struct s_coord	coord;
	struct s_coord	player_pos;
	struct s_coord	exit_pos;
	int				collectible_tot;
	int				collectible_cnt;
}					t_map;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*floor_img;
	void			*sprite_back_img;
	void			*sprite_face_img;
	void			*sprite_left_img;
	void			*sprite_right_img;
	void			*tree_img;
	void			*collectible_img;
	void			*exit_img;
	struct s_map	*map;
}					t_mlx_data;

// init map
void				init_map(t_map *map, char **buffer, t_coord pos, int i);
void				formating(t_map *map, char *buffer);
int					cross_check_loop(t_map *map, int y);

// map parsing
t_coord				file_len(const char **argv);
t_map				*map_allocation(const char **argv);
t_map				*map_formating(const char **argv);
void				free_map(t_map *map);

// map validity check
int					cross_check(t_map *map);
int					check_elem(t_map *map);

// map validity check 2
t_coord				get_exit_coord(t_map *map);
int					check_arround(t_map *map, t_coord pos);
int					fill(t_map *map, t_coord pos);
int					check_elem_loop(t_map *map, int *p_count, int *c_count,
						int y);

// windows managements
t_mlx_data			*create_window(t_map *map);
int					init_img_sec(t_mlx_data *data);
void				free_img(t_mlx_data *data);
int					escape_input(t_mlx_data *data);

// input_event
int					handle_input(int keysym, t_mlx_data *data);
int					escape_input(t_mlx_data *data);

// map rendering
void				render_map(t_mlx_data *data);
int					check_collectible_cnt(t_mlx_data *data);
void				check_exit(t_mlx_data *data);

// moove management
void				moove_right(t_mlx_data *data);
void				moove_left(t_mlx_data *data);
void				moove_top(t_mlx_data *data);
void				moove_bottom(t_mlx_data *data);

#endif
