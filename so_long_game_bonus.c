/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:32:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/27 16:37:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_on_door(t_mlx_data *data, t_pos *player_pos, int x_pos,
		int y_pos)
{
	if (player_pos->x == x_pos)
		put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/si_cdoor.xpm");
	else if (player_pos->x < x_pos)
		move_right_to_door(data, player_pos, x_pos, y_pos);
	else if (player_pos->x > x_pos)
		move_left_to_door(data, player_pos, x_pos, y_pos);
}

void	put_leaved_door(t_mlx_data *data, t_pos *player_pos)
{
	if (is_collectible(data->grid))
		put_elem_to_win(data, player_pos->x, player_pos->y,
			"./assets/xpm/closed_door.xpm");
	else
		put_elem_to_win(data, player_pos->x, player_pos->y,
			"./assets/xpm/opened_door.xpm");
}

void	leave_door(t_mlx_data *data, t_pos *player_pos, int x_pos, int y_pos)
{
	if (player_pos->x < x_pos)
		leave_door_to_right(data, player_pos, x_pos, y_pos);
	else if (player_pos->x > x_pos)
		leave_door_to_left(data, player_pos, x_pos, y_pos);
	else if (player_pos->x == x_pos)
	{
		put_elem_to_win(data, data->door.x, data->door.y,
			"./assets/xpm/opened_door.xpm");
		put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/sprite_idle.xpm");
	}
}

int	alter_grid(t_mlx_data *data, t_pos *player_pos, int x_pos, int y_pos)
{
	if (data->grid[y_pos][x_pos] == '1')
		return (0);
	data->grid[player_pos->y][player_pos->x] = '0';
	data->grid[y_pos][x_pos] = 'P';
	data->moves += 1;
	if (is_pos_on_door(data, player_pos->x, player_pos->y))
		return (leave_door(data, player_pos, x_pos, y_pos), 1);
	else
		put_elem_to_win(data, player_pos->x, player_pos->y,
			"./assets/xpm/ground.xpm");
	if (is_pos_on_door(data, x_pos, y_pos))
		put_player_on_door(data, player_pos, x_pos, y_pos);
	else if (player_pos->x == x_pos)
		put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/sprite_idle.xpm");
	else if (player_pos->x < x_pos)
		move_to_right(data, player_pos, x_pos, y_pos);
	else if (player_pos->x > x_pos)
		move_to_left(data, player_pos, x_pos, y_pos);
	if (!is_collectible(data->grid) && !is_pos_on_door(data, player_pos->x,
			player_pos->y))
		put_elem_to_win(data, data->door.x, data->door.y,
			"./assets/xpm/opened_door.xpm");
	return (1);
}

int	move_player(t_mlx_data *data, char dir)
{
	t_pos	player_pos;

	player_pos.x = get_x(data->grid, 'P');
	player_pos.y = get_y(data->grid, 'P');
	if (dir == 'u')
		return (alter_grid(data, &player_pos, player_pos.x, player_pos.y - 1));
	else if (dir == 'd')
		return (alter_grid(data, &player_pos, player_pos.x, player_pos.y + 1));
	else if (dir == 'l')
		return (alter_grid(data, &player_pos, player_pos.x - 1, player_pos.y));
	else if (dir == 'r')
		return (alter_grid(data, &player_pos, player_pos.x + 1, player_pos.y));
	return (1);
}
