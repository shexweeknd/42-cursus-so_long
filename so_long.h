/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:49:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 09:14:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17
# define WIN_HEIGHT 720
# define WIN_WIDTH 480
# define BUFFER_SIZE 1024

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		tile_x_px;
	int		tile_y_px;
	char	**grid;
	int		x;
	int		y;
}			t_mlx_data;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

// fonctions pour sortir de la fenetre
int			handle_keypress(int keycode, t_mlx_data *data);
int			handle_exit(t_mlx_data *data);
void		set_exit_hooks(t_mlx_data *data);

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
int			is_exit(char **grid);
int			is_way_to_exit(t_mlx_data *map);

// fonctions pour render les map et les images
void		*compute_xpm_to_win(t_mlx_data *data, int *img_width,
				int *img_height, char *file_path);
void		put_ground_to_win(t_mlx_data *data);

// fonctions utiles pour mlx
void		free_mlx_data(t_mlx_data *data);

// fonctions pour les sorties d'erreur
void		render_exit(t_mlx_data *data, char *message);

// fonctions pour les debug
void		print_grid(char **map);

#endif
