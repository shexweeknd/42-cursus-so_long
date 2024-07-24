/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/24 11:24:36 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile_px(t_mlx_data *data)
{
	void	*img;
	int		h;
	int		w;

	img = compute_xpm_to_win(data, &w, &h, "./assets/xpm/ground.xpm");
	if (!img)
		return ;
	data->tile_x_px = w;
	data->tile_y_px = h;
	mlx_destroy_image(data->mlx, img);
}

void	destroy_display(t_mlx_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	render_exit(NULL, "Error\n");
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (render_exit(NULL, "Error\n"), 0);
	if (argc != 2)
		return (destroy_display(&data), 0);
	data.grid = malloc(sizeof(char *) * (count_lines(argv[1]) + 1));
	if (!data.grid || !fullfill_grid(data.grid, argv[1])
		|| !is_validgrid(data.grid) || !uniform_map(&data))
		return (destroy_display(&data), 0);
	if (!grid_rules(&data))
		return (ft_free_splitted(data.grid), destroy_display(&data), 0);
	set_tile_px(&data);
	data.win = mlx_new_window(data.mlx, data.tile_x_px * data.x, data.tile_y_px
			* data.y, "so_long hramaros");
	if (!data.win)
		return (ft_free_splitted(data.grid), destroy_display(&data), 1);
	set_hooks(&data);
	data.moves = 0;
	render_map(&data);
	mlx_loop(data.mlx);
	return (ft_free_splitted(data.grid), free_mlx_data(&data), 0);
}
