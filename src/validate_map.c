/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:21:07 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/20 17:08:48 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../libs/libft/libft.h"
#include <stdio.h>

int	is_rectangular(t_game *game)
{
	int	len;
	int	i;

	if (!game || !game->map || !game->map[0])
		return (0);
	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	len;

	len = 0;
	while (game->map[0][len] == '1')
		len++;
	i = -1;
	while (game->map[++i])
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			return (0);
	return (1);
}

int	is_valid_char(char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != '1' && c != '0')
		return (0);
	return (1);
}

int	validate_components(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!is_valid_char(game->map[i][j]))
				return (0);
			if (game->map[i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->coin++;
		}
	}
	if (game->player != 1 || game->exit != 1 || game->coin < 1)
		return (0);
	return (1);
}
