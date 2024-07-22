/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:45:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:46:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_format(char *str)
{
	int	name_size;

	name_size = ft_strlen(str);
	if (name_size-- < 5)
		return (0);
	if (str[name_size--] != 'r')
		return (0);
	if (str[name_size--] != 'e')
		return (0);
	if (str[name_size--] != 'b')
		return (0);
	if (str[name_size--] != '.')
		return (0);
	return (1);
}

int	valid_rowcol(char **grid)
{
	int		index;
	size_t	col;

	index = 0;
	col = ft_strlen_no_nl(grid[index]);
	while (grid[index])
	{
		if (ft_strlen_no_nl(grid[index]) == 0)
			break ;
		if (ft_strlen_no_nl(grid[index]) != col)
			return (0);
		index++;
	}
	while (grid[index])
	{
		if (*grid[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}

int	fullfill_grid(char **grid, char *file_path)
{
	int	fd;

	if (!verify_format(file_path))
		return (0);
	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (free(grid), 0);
	*grid = get_next_line(fd);
	while (*grid)
	{
		grid++;
		*grid = get_next_line(fd);
	}
	return (close(fd), 1);
}

int	is_validgrid(char **grid)
{
	if (!valid_rowcol(grid))
		return (ft_free_splitted(grid), 0);
	if (count_rows(grid) == ft_strlen_no_nl(grid[0]))
		return (ft_free_splitted(grid), 0);
	return (1);
}

int	uniform_map(t_map *map)
{
	int	index;

	index = 0;
	while (map->grid[index])
	{
		if (*map->grid[index] == '\n')
		{
			free(map->grid[index]);
			map->grid[index] = NULL;
		}
		else
			map->grid[index][ft_strlen_no_nl(map->grid[index])] = 0;
		index++;
	}
	map->x = ft_strlen_no_nl(*map->grid);
	map->y = get_twodim_size(map->grid);
	return (1);
}
