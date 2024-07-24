/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:49:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/24 14:15:12 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		tile_x_px;
	int		tile_y_px;
	char	**grid;
	int		x;
	int		y;
	int		moves;
	t_pos	door;
}			t_mlx_data;

// fonctions pour les hooks
int			handle_keyrelease(int keycode, t_mlx_data *data);
int			move_player(t_mlx_data *data, char dir);
int			handle_exit(t_mlx_data *data);
void		set_hooks(t_mlx_data *data);
int			is_player_winning(t_mlx_data *data);
int			is_pos_on_door(t_mlx_data *data, int x, int y);

// fonctions pour traitement de ber
int			verify_format(char *str);
int			valid_rowcol(char **grid);
int			fullfill_grid(char **grid, char *file_path);
int			is_validgrid(char **grid);
int			uniform_map(t_mlx_data *map);

// fonctions utils du traitement de ber
size_t		count_lines(char *file_path);
size_t		count_rows(char **grid);

// fonctions pour les regles de la map
int			grid_rules(t_mlx_data *map);
int			is_wall_correct(char **grid);
int			is_one_player(char **grid);
int			is_collectible(char **grid);
int			is_player_winning(t_mlx_data *data);
int			is_exit(char **grid);
int			is_way_to_exit(t_mlx_data *map);

// fonctions pour get les positions du player
int			get_y(char **grid, char c);
int			get_x(char **grid, char c);

// fonctions pour render les map et les images
void		*compute_xpm_to_win(t_mlx_data *data, int *img_width,
				int *img_height, char *file_path);
void		put_elem_to_win(t_mlx_data *data, int x_offset, int y_offset,
				char *xpm_path);
void		render_map(t_mlx_data *data);

// fonctions utiles pour mlx
void		free_mlx_data(t_mlx_data *data);

// fonctions pour les sorties d'erreur
void		render_exit(t_mlx_data *data, char *message);

// fonctions pour les debug
void		print_grid(char **map);

#endif
