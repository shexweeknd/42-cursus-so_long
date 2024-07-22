/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:19:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 13:59:11 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*compute_xpm_to_win(t_mlx_data *data, int *img_width, int *img_height, char *file_path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, file_path, img_width,
			img_height);
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
	int		x_rep;
	int		y_rep;

	img = compute_xpm_to_win(data, &x_offset, &y_offset, "./assets/xpm/Hills.xpm");
	if (!img)
		return ;
	x_rep = 0;
	while (x_rep < data->x / x_offset)
	{
		y_rep = 0;
		while (y_rep < data->y / y_offset)
		{
			mlx_put_image_to_window(data->mlx, data->win, img, x_rep * y_offset,
				y_rep * y_offset);
			y_rep++;
		}
		x_rep++;
	}
}
