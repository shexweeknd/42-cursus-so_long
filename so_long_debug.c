/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:59:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/21 11:31:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		ft_putstr(map[index]);
		index++;
	}
}
