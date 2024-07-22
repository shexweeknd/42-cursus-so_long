/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_grid_rules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:32:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 14:01:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	grid_rules(t_mlx_data *map)
{
	if (!is_wall_correct(map->grid))
		return (0);
	if (!is_one_player(map->grid))
		return (0);
	if (!is_collectible(map->grid))
		return (0);
	if (!is_exit(map->grid))
		return (0);
	if (!is_way_to_exit(map))
		return (0);
	return (1);
}
