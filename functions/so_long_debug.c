/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:59:42 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:24:15 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_grid(char **grid)
{
	int	index;

	index = 0;
	while (grid[index])
	{
		ft_putstr(grid[index]);
		ft_putchar_fd('\n', 1);
		index++;
	}
}
