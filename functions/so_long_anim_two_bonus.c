/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_anim_two_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:51:22 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/27 16:51:44 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	leave_door_to_right(t_mlx_data *data, t_pos *player_pos, int x_pos,
		int y_pos)
{
	(void)x_pos;
	(void)y_pos;
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/lr_cd/lr_cd_1.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/lr_cd/lr_cd_2.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/lr_cd/lr_cd_3.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/bonus/lr_cd/lr_cd_4.xpm");
}

void	leave_door_to_left(t_mlx_data *data, t_pos *player_pos, int x_pos,
		int y_pos)
{
	(void)x_pos;
	(void)y_pos;
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ll_cd/ll_cd_1.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ll_cd/ll_cd_2.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ll_cd/ll_cd_3.xpm");
	usleep(70000);
	put_elem_to_win(data, player_pos->x - 1, player_pos->y,
		"./assets/xpm/bonus/ll_cd/ll_cd_4.xpm");
}
