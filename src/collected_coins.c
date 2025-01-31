/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collected_coins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:49:01 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 18:35:57 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	collected_coins(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->y)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
