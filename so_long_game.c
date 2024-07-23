/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:32:40 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collectible_left(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	alter_grid(t_mlx_data *data, t_pos *player_pos, int x_pos, int y_pos)
{
	if (data->grid[y_pos][x_pos] == '1' || (data->grid[y_pos][x_pos] == 'E'
			&& is_collectible_left(data->grid)))
		return (0);
	data->grid[player_pos->y][player_pos->x] = '0';
	data->grid[y_pos][x_pos] = 'P';
	data->moves += 1;
	put_elem_to_win(data, player_pos->x, player_pos->y,
		"./assets/xpm/ground.xpm");
	put_elem_to_win(data, x_pos, y_pos, "./assets/xpm/sprite.xpm");
	if (!is_collectible(data->grid))
		put_elem_to_win(data, get_x(data->grid, 'E'), get_y(data->grid, 'E'),
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
