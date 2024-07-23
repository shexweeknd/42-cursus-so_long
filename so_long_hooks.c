/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:22:02 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/23 16:12:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_keys_to_play(int keycode, t_mlx_data *data)
{
	if (keycode == 119 || keycode == 65362)
	{
		if (move_player(data, 'u'))
			ft_printf("move done: %d\r", data->moves);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (move_player(data, 'd'))
			ft_printf("move done: %d\r", data->moves);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		if (move_player(data, 'l'))
			ft_printf("move done: %d\r", data->moves);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (move_player(data, 'r'))
			ft_printf("move done: %d\r", data->moves);
	}
}

int	handle_keyrelease(int keycode, t_mlx_data *data)
{
	if (keycode == 53 || keycode == 65307)
		handle_exit(data);
	else
		check_keys_to_play(keycode, data);
	if (!is_exit(data->grid))
	{
		ft_printf("move done: %d\nLe jeu est termine\n", data->moves);
		handle_exit(data);
	}
	return (0);
}

int	handle_exit(t_mlx_data *data)
{
	ft_free_splitted(data->grid);
	render_exit(data, "Fermeture de la fenetre...\n");
	return (0);
}

void	set_hooks(t_mlx_data *data)
{
	mlx_hook(data->win, KEY_PRESS, 1L << 0, handle_keyrelease, data);
	mlx_hook(data->win, KEY_EXIT, 1L << 17, handle_exit, data);
}
