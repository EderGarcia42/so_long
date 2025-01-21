/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:31:44 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/21 14:31:37 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = ft_strlen(game->map[0]) * TILE_SIZE;
	win_height = game->y * TILE_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_width, win_height, WINDOW_TITLE);
}
