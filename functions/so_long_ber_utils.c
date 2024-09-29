/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ber_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:46:41 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:48:16 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	size_t	result;

	fd = open(file_path, O_RDONLY);
	if (fd <= 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), free(line), 0);
	result = 1;
	while (line)
	{
		result++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), result);
}

size_t	count_rows(char **grid)
{
	size_t	index;

	index = 0;
	while (grid[index] && *grid[index] != '\n')
		index++;
	return (index);
}
