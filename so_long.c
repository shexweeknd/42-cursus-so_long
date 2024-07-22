/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:56:31 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_display(t_mlx_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	render_exit(NULL, "Error\n");
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_map		map;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (render_exit(NULL, "Error\n"), 0);
	if (argc != 2)
		return (destroy_display(&data), 0);
	map.grid = malloc(sizeof(char *) * (count_lines(argv[1]) + 1));
	if (!map.grid || !fullfill_grid(map.grid, argv[1])
		|| !is_validgrid(map.grid) || !uniform_map(&map))
		return (destroy_display(&data), 0);
	if (!grid_rules(&map))
		return (ft_free_splitted(map.grid), destroy_display(&data), 0);
	ft_printf("map is correct !\n");
	return (ft_free_splitted(map.grid), mlx_destroy_display(data.mlx),
		free(data.mlx), 0);
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
