/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pce_rules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:36:47 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:37:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_one_player(char **grid)
{
	int	i;
	int	j;
	int	occ;

	occ = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'P')
				occ++;
			j++;
		}
		i++;
	}
	if (occ != 1)
		return (0);
	return (1);
}

int	is_exit(char **grid)
{
	int	i;
	int	j;
	int	occ;

	occ = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'E')
				occ++;
			j++;
		}
		i++;
	}
	if (occ != 1)
		return (0);
	return (1);
}

int	is_collectible(char **grid)
{
	int	i;
	int	j;
	int	occ;

	occ = 0;
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'C')
				occ++;
			j++;
		}
		i++;
	}
	if (occ < 1)
		return (0);
	return (1);
}
