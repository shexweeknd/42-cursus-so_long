/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/21 11:31:58 by hramaros         ###   ########.fr       */
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

size_t	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	size_t	result;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), free(line), 0);
	result = 1;
	while (line)
	{
		result++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), result);
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
	while (grid[index] && (*grid[index] == '\n'))
	{
		if (ft_strlen_no_nl(grid[index]) > 0)
			return (0);
		index++;
	}
	return (1);
}

size_t	count_rows(char **grid)
{
	size_t	index;

	index = 0;
	while (grid[index] && *grid[index] != '\n')
		index++;
	return (index);
}

int	is_validgrid(char **grid)
{
	if (!valid_rowcol(grid))
		return (ft_free_splitted(grid), 0);
	if (count_rows(grid) == ft_strlen_no_nl(grid[0]))
		return (ft_free_splitted(grid), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_map		map;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (argc != 2)
		return (mlx_destroy_display(data.mlx), free(data.mlx), render_exit(NULL,
				"Error\n"), 0);
	map.grid = malloc(sizeof(char *) * (count_lines(argv[1]) + 1));
	if (!map.grid || !fullfill_grid(map.grid, argv[1])
		|| !is_validgrid(map.grid))
		return (mlx_destroy_display(data.mlx), free(data.mlx), render_exit(NULL,
				"Error\n"), 0);
	print_map(map.grid);
	return (ft_free_splitted(map.grid), mlx_destroy_display(data.mlx), free(data.mlx), 0);
	data.win = mlx_new_window(data.mlx, WIN_HEIGHT, WIN_WIDTH,
			"so_long hramaros");
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	set_exit_hooks(&data);
	// TODO debug de put_ground_to_win
	put_ground_to_win(&data);
	// TODO importation d'une image sur la fenetre
	mlx_loop(data.mlx);
	return (free_mlx_data(&data), 0);
}
