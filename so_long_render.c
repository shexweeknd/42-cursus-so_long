/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:19:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 09:31:04 by hramaros         ###   ########.fr       */
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
		render_exit(data, "Failed to compute image\n");
		return (NULL);
	}
	return (img);
}

void	put_ground_to_win(t_mlx_data *data)
{
	void	*img;
	int		x_offset;
	int		y_offset;

	img = compute_xpm_to_win(data, &x_offset, &y_offset,
			"./assets/xpm/test.xpm");
	if (!img)
		return ;
	y_offset = 0;
	while (y_offset < data->y)
	{
		x_offset = 0;
		while (x_offset < data->x)
		{
			mlx_put_image_to_window(data->mlx, data->win, img, data->tile_x_px
				* x_offset, data->tile_y_px * y_offset);
			x_offset++;
		}
		y_offset++;
	}
	mlx_destroy_image(data->mlx, img);
}
