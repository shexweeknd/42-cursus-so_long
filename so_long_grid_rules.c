/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_grid_rules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:32:08 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/21 16:44:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_only_one(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	is_closed_by_one(char *str)
{
	if (*str != '1')
		return (0);
	while (*str)
	{
		if (*(str + 1) == '\0')
			break ;
		str++;
	}
	if (*str != '1')
		return (0);
	return (1);
}

int	is_wall_correct(char **grid)
{
	int	index;

	if (!is_only_one(grid[0]))
		return (0);
	index = 0;
	while (grid[index])
	{
		if (grid[index + 1] == NULL)
			break ;
		if (!is_closed_by_one(grid[index]))
			return (0);
		index++;
	}
	if (!is_only_one(grid[index]))
		return (0);
	return (1);
}

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

int	map_rules(char **grid)
{
	// is wall correct
	if (!is_wall_correct(grid))
		return (0);
	// is one player
	if (!is_one_player(grid))
		return (0);
	// is collectible
	if (!is_collectible(grid))
		return (0);
	// is exit
	if (!is_exit(grid))
		return (0);
	// is way to exit
	// a changer en liste chainee puis verifier dans une autre fonction
	return (1);
}
