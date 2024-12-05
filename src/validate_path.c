/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:21:11 by edegarci          #+#    #+#             */
/*   Updated: 2024/12/05 15:14:32 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"

static int	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	flood_fill(char **map, int x, int y, int *components)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		components[0]--;
	if (map[y][x] == 'E')
		components[1]--;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, components);
	flood_fill(map, x - 1, y, components);
	flood_fill(map, x, y + 1, components);
	flood_fill(map, x, y - 1, components);
}

int	is_path_valid(t_game *game)
{
	char	**map_copy;
	int		components[2];

	if (!find_player_position(game))
		return (0);
	map_copy = ft_strdup_2d(game->map);
	if (!map_copy)
		return (0);
	components[0] = game->coin;
	components[1] = 1;
	flood_fill(map_copy, game->x, game->y, components);
	ft_free_2d(map_copy);
	return (components[0] == 0 && components[1] == 0);
}
