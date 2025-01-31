/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:42:12 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 18:43:24 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../libs/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	count_lines(const char *path)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR_07);
	lines = 0;
	line = read_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (lines);
}

void	count_coins(t_game *game)
{
	int	x;
	int	y;

	game->total_coins = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_coins++;
			x++;
		}
		y++;
	}
}

void	count_total_coins(t_game *game)
{
	int	i;
	int	j;

	game->total_coins = 0;
	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == 'C')
			{
				game->total_coins++;
			}
			j++;
		}
		i++;
	}
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_putstr_fd(game->map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
