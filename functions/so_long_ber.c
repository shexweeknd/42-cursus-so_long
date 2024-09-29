/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:45:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/24 13:52:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_format(char *str)
{
	int		name_size;
	char	**basenames;
	char	*file_name;

	basenames = ft_split_by(str, '/');
	if (!basenames)
		return (0);
	file_name = basenames[get_twodim_size(basenames) - 1];
	name_size = ft_strlen(file_name);
	if (name_size-- < 5)
		return (ft_free_splitted(basenames), 0);
	if (file_name[name_size--] != 'r')
		return (ft_free_splitted(basenames), 0);
	if (file_name[name_size--] != 'e')
		return (ft_free_splitted(basenames), 0);
	if (file_name[name_size--] != 'b')
		return (ft_free_splitted(basenames), 0);
	if (file_name[name_size--] != '.')
		return (ft_free_splitted(basenames), 0);
	return (ft_free_splitted(basenames), 1);
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
			return (0);
		if (ft_strlen_no_nl(grid[index]) != col)
			return (0);
		index++;
	}
	return (1);
}

int	fullfill_grid(char **grid, char *file_path)
{
	int	fd;

	if (!verify_format(file_path))
		return (free(grid), 0);
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
	return (1);
}

int	uniform_map(t_mlx_data *map)
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
