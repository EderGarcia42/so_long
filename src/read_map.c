/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:59 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/05 14:40:18 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../libs/libft/libft.h"

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
	int		i;
	char	*line;

	game->map = NULL;
	fd = open_map_file(game->path);
	allocate_map(game);
	i = 0;
	line = get_next_line(fd);
	while (i < game->y && line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	print_map(game);
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
