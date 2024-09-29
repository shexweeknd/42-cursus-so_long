/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_way_rules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:38:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 15:13:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_y(char **grid, char c)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

int	get_x(char **grid, char c)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

void	flood_canva(char **grid, t_pos size, t_pos curr)
{
	if (curr.x >= size.x || curr.y >= size.y || curr.x <= 0 || curr.y <= 0
		|| grid[curr.y][curr.x] == '1' || grid[curr.y][curr.x] == 'F')
		return ;
	grid[curr.y][curr.x] = 'F';
	flood_canva(grid, size, (t_pos){curr.x - 1, curr.y});
	flood_canva(grid, size, (t_pos){curr.x + 1, curr.y});
	flood_canva(grid, size, (t_pos){curr.x, curr.y - 1});
	flood_canva(grid, size, (t_pos){curr.x, curr.y + 1});
}

int	check_canva(char **grid)
{
	int	c_occ;
	int	e_occ;
	int	x;
	int	y;

	c_occ = 0;
	e_occ = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				c_occ++;
			if (grid[y][x] == 'E')
				e_occ++;
			x++;
		}
		y++;
	}
	if (!c_occ && !e_occ)
		return (1);
	return (0);
}

int	is_way_to_exit(t_mlx_data *map)
{
	char	**canva;

	canva = ft_str_twodim_dup(map->grid);
	if (!canva)
		return (0);
	flood_canva(canva, (t_pos){map->x - 1, map->y - 1}, (t_pos){get_x(canva,
			'P'), get_y(canva, 'P')});
	if (!check_canva(canva))
		return (ft_free_splitted(canva), 0);
	return (ft_free_splitted(canva), 1);
}
