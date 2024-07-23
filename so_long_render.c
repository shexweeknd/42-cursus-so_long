/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:19:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 13:40:41 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*compute_xpm_to_win(t_mlx_data *data, int *img_width, int *img_height,
		char *file_path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, file_path, img_width, img_height);
	if (!img)
	{
		ft_free_splitted(data->grid);
		render_exit(data, "Failed to compute image\n");
		return (NULL);
	}
	return (img);
}

void	put_elem_to_win(t_mlx_data *data, int x_offset, int y_offset,
		char *xpm_path)
{
	void	*img;
	int		width;
	int		height;

	img = compute_xpm_to_win(data, &width, &height, xpm_path);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, img, data->tile_x_px
		* x_offset, data->tile_y_px * y_offset);
	mlx_destroy_image(data->mlx, img);
}

void	render_gw(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->grid[y][x] == '1')
				put_elem_to_win(data, x, y, "./assets/xpm/wall.xpm");
			else if (data->grid[y][x] == '0')
				put_elem_to_win(data, x, y, "./assets/xpm/ground.xpm");
			x++;
		}
		y++;
	}
}

void	render_pce(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->grid[y][x] != '1' && data->grid[y][x] != '0')
				put_elem_to_win(data, x, y, "./assets/xpm/ground.xpm");
			if (data->grid[y][x] == 'P')
				put_elem_to_win(data, x, y, "./assets/xpm/sprite.xpm");
			else if (data->grid[y][x] == 'C')
				put_elem_to_win(data, x, y, "./assets/xpm/collectible.xpm");
			else if (data->grid[y][x] == 'E' && is_collectible(data->grid))
				put_elem_to_win(data, x, y, "./assets/xpm/closed_door.xpm");
			else if (data->grid[y][x] == 'E' && !is_collectible(data->grid))
				put_elem_to_win(data, x, y, "./assets/xpm/opened_door.xpm");
			x++;
		}
		y++;
	}
}

void	render_map(t_mlx_data *data)
{
	render_gw(data);
	render_pce(data);
}
