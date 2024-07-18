/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/18 09:36:22 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_format(char *str)
{
	int	name_size;

	name_size = ft_strlen(str);
	if (name_size-- < 4)
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

int	check_map(char *str)
{
	int	fd;

	if (!verify_format(str))
		return (0);
	fd = open(str, O_RDONLY, NULL);
	if (fd < 0)
		return (0);
	return (close(fd), 1);
}

int	get_rows_nbr(char *filename)
{
	int		result;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY, NULL);
	if (fd < 0)
		return (0);
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), 0);
	result = 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		result++;
	}
	return (close(fd), result);
}

int	get_col_nbr(char *filename)
{
	int		result;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY, NULL);
	if (fd < 0)
		return (0);
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), 0);
	result = ft_strlen(tmp) - 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
		{
			if (get_next_line(fd))
				return (close(fd), 0);
			else
				return (close(fd), result);
		}
		if ((ft_strlen(tmp) - 1) != (size_t)result)
			return (free(tmp), close(fd), 0);
	}
	return (close(fd), result);
}

char	**parse_ber(char *filename, int rows_nbr, int col_nbr)
{
	char	**result;
	int		index;
	char	*buffer;
	int		fd;

	if (!rows_nbr || !col_nbr)
		return (render_exit((void *)0, "col or row invalids.\n"), NULL);
	fd = open(filename, O_RDONLY, NULL);
	if (fd < 0)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (rows_nbr + 1));
	if (!result)
		return (close(fd), NULL);
	result[rows_nbr] = NULL;
	buffer = get_next_line(fd);
	if (!buffer)
		return (ft_free_splitted(result), close(fd), NULL);
	index = 0;
	while (buffer)
	{
		result[index++] = buffer;
		buffer = get_next_line(fd);
	}
	return (close(fd), result);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	char		**map;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (argc != 2 || (argc == 2 && !check_map(argv[1])))
		return (mlx_destroy_display(data.mlx), render_exit(NULL, "Error\n"), 0);
	map = parse_ber(argv[1], get_rows_nbr(argv[1]), get_col_nbr(argv[1]));
	if (!map || !map_rules(map))
		return (mlx_destroy_display(data.mlx), free(data.mlx), render_exit(NULL,
				"Error\n"), 0);
	return (0);
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
