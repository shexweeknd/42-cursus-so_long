/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_animations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:40:04 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/27 16:02:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_mlx_data *data, t_pos *player_pos, int x_pos, int y_pos)
{
	usleep(55000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/mr/mr_0.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/mr/mr_1.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/mr/mr_2.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/mr/mr_3.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/mr/mr_4.xpm");
	usleep(55000);
	put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/sprite_right.xpm");
}

void	move_to_left(t_mlx_data *data, t_pos *player_pos, int x_pos, int y_pos)
{
	usleep(55000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ml/ml_0.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ml/ml_1.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ml/ml_2.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ml/ml_3.xpm");
	usleep(55000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ml/ml_4.xpm");
	usleep(55000);
	put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/sprite_left.xpm");
}
