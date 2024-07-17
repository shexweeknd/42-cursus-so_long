/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:19:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/17 11:20:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*compute_xpm_to_win(t_mlx_data *data, int *img_width, int *img_height)
{
	void	*img;
	char	*relative_path;

	relative_path = "./assets/xpm/Hills.xpm";
	img = mlx_xpm_file_to_image(data->mlx, relative_path, img_width,
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

	img = compute_xpm_to_win(data, &x_offset, &y_offset);
	if (!img)
		return ;
	x_rep = 0;
	while (x_rep < WIN_WIDTH / x_offset)
	{
		y_rep = 0;
		while (y_rep < WIN_HEIGHT / y_offset)
		{
			mlx_put_image_to_window(data->mlx, data->win, img, x_rep * y_offset,
				y_rep * y_offset);
			y_rep++;
		}
		x_rep++;
	}
}