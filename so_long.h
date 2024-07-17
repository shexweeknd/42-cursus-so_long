/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:49:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/17 13:21:26 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17
# define WIN_HEIGHT 720
# define WIN_WIDTH 480
# define IMG_WIDTH
# define IMG_HEIGHT

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
}			t_mlx_data;

// fonctions pour sortir de la fenetre
int			handle_keypress(int keycode, t_mlx_data *data);
int			handle_exit(void *data);
void		set_exit_hooks(t_mlx_data *data);

// fonctions pour les rendering d'images
void		put_ground_to_win(t_mlx_data *data);
void		*compute_xpm_to_win(t_mlx_data *data, int *img_width,
				int *img_height);

// fonctions pour render les map et les images
void		*compute_xpm_to_win(t_mlx_data *data, int *img_width,
				int *img_height);
void		put_ground_to_win(t_mlx_data *data);

// fonctions pour les sorties d'erreur
void		render_exit(t_mlx_data *data, char *message);

#endif
