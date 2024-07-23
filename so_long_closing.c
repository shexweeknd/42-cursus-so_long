/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_closing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:22:02 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 09:15:30 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_mlx_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
	{
		ft_free_splitted(data->grid);
		render_exit(data, "Fermeture de la fenetre...\n");
	}
	return (0);
}

int	handle_exit(t_mlx_data *data)
{
	ft_free_splitted(data->grid);
	render_exit(data, "Fermeture de la fenetre...\n");
	return (0);
}

void	set_exit_hooks(t_mlx_data *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, KEY_EXIT, 1L << 17, handle_exit, data);
}
