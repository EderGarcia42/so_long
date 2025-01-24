/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:18 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 15:19:03 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	handle_tile_event(t_game *game, int dx, int dy)
{
	if (game->map[game->player_y][game->player_x] == 'C')
		game->map[game->player_y][game->player_x] = '0';
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (collected_coins(game, 0, 0))
		{
			ft_putstr_fd(WIN_01, 1);
			handle_exit(game);
		}
		else
		{
			ft_putstr_fd(WIN_02, 1);
			game->player_x -= dx;
			game->player_y -= dy;
		}
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		handle_tile_event(game, dx, dy);
		game->map[game->player_y][game->player_x] = 'P';
	}
}
