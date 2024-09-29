/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:56:49 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/24 11:57:05 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_player_winning(t_mlx_data *data)
{
	if (is_collectible(data->grid))
		return (0);
	else if (!is_collectible(data->grid) && get_x(data->grid,
			'P') == data->door.x && get_y(data->grid, 'P') == data->door.y)
		return (1);
	return (0);
}

int	is_pos_on_door(t_mlx_data *data, int x, int y)
{
	if (x == data->door.x && y == data->door.y)
		return (1);
	return (0);
}
