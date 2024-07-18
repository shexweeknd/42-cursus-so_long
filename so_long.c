/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/18 11:36:47 by hramaros         ###   ########.fr       */
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

int	open_ber(char *str)
{
	int	fd;

	if (!verify_format(str))
		return (0);
	fd = open(str, O_RDONLY, NULL);
	if (fd < 0)
		return (0);
	return (fd);
}

int	get_rows_nbr(int fd)
{
	int		result;
	char	*tmp;

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
	return (result);
}

int	get_col_nbr(int fd)
{
	int		result;
	char	*tmp;

	tmp = get_next_line(fd);
	if (!tmp || ft_strlen_no_nl(tmp) < 2)
		return (close(fd), 0);
	result = ft_strlen_no_nl(tmp);
	while (tmp && *tmp != '\n')
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && *tmp != '\n' && ft_strlen_no_nl(tmp) != (size_t)result)
			return (free(tmp), 0);
	}
	while (tmp)
	{
		if (tmp && *tmp != '\n')
			return (free(tmp), 0);
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (result);
}

char	**parse_ber(int fd, int rows_nbr, int col_nbr)
{
	char	**result;
	int		index;
	char	*buffer;

	if (!rows_nbr || !col_nbr)
		return (close(fd), NULL);
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
	int			fd;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	fd = open_ber(argv[1]);
	if (argc != 2 || (argc == 2 && !fd))
		return (mlx_destroy_display(data.mlx), free(data.mlx), render_exit(NULL,
				"Error\n"), 0);
	map = parse_ber(fd, get_rows_nbr(fd), get_col_nbr(fd));
	if (!map || !map_rules(map))
		return (mlx_destroy_display(data.mlx), free(data.mlx), render_exit(NULL,
				"Error\n"), 0);
	print_map(map);
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
