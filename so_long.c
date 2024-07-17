/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:48:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/17 09:11:08 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_EXIT 17

int	handle_keypress(int keycode, t_mlx_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		render_exit(data, "Fermeture de la fenetre...\n");
	return (0);
}

int	handle_exit(void *data)
{
	render_exit(data, "Fermeture de la fenetre...\n");
	return (0);
}

void	set_exit_hooks(t_mlx_data *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, KEY_EXIT, 1L << 17, handle_exit, data);
}

int	main(void)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 720, 480, "so_long hramaros");
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	set_exit_hooks(&data);
	// TODO affichage de pixels sur la fenetre
	// TODO importation d'une image sur la fenetre
	mlx_loop(data.mlx);
	return (mlx_destroy_window(data.mlx, data.win),
		mlx_destroy_display(data.mlx), 0);
}
