/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:59 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/21 14:25:03 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../libs/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	open_map_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR_07);
	return (fd);
}

static void	allocate_map(t_game *game)
{
	game->y = count_lines(game->path);
	if (game->y < 1)
		ft_error(ERROR_09);
	game->map = (char **)malloc(sizeof(char *) * (game->y + 1));
	if (!game->map)
		ft_error(ERROR_08);
}
void	read_map(t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open_map_file(game->path);
	allocate_map(game);
	i = 0;
	line = read_line(fd);
	while (line)
	{
		if (line[0] != '\0')
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			game->map[i++] = line;
		}
		else
			free(line);
		line = read_line(fd);
	}
	game->map[i] = NULL;
	game->y = i;
	close(fd);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}
