/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/17 16:26:43 by hramaros         ###   ########.fr       */
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
	// TODO read the file and check if any forbidden rules applied to the map is set
	return (close(fd), 1);
}

// TODO
char	**parse_ber(char *filename)
{
	(void)filename;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	char		**map;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (argc != 2 || (argc == 2 && !check_map(argv[1])))
		return (render_exit((void *)0, "Error\n"), 0);
	// TODO fonction qui parse le .*ber et qui render l'ecran en fonction de
	map = parse_ber(argv[1]);
	if (!map)
		return (render_exit((void *)0, "Error\n"), 0);
	data.win = mlx_new_window(data.mlx, WIN_HEIGHT, WIN_WIDTH,
			"so_long hramaros");
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	set_exit_hooks(&data);
	// TODO debug de put_ground_to_win
	put_ground_to_win(&data);
	// TODO importation d'une image sur la fenetre
	mlx_loop(data.mlx);
	return (mlx_destroy_window(data.mlx, data.win),
		mlx_destroy_display(data.mlx), 0);
}
