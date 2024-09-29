/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_rules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:35:36 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:36:12 by hramaros         ###   ########.fr       */
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
