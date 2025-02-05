/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:18 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/31 18:00:30 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	handle_tile_event(t_game *game, int dx, int dy)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->collected_coins++;
		ft_putstr_fd(COINS, 1);
		ft_putnbr_fd(game->collected_coins, 1);
		ft_putstr_fd("/", 1);
		ft_putnbr_fd(game->total_coins, 1);
		ft_putstr_fd("\n", 1);
	}
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (game->collected_coins == game->total_coins)
		{
			ft_putstr_fd(WIN, 1);
			handle_exit(game);
		}
		else
		{
			ft_putstr_fd(WARNING, 1);
			game->ondoor = 1;
		}
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x >= 0 && new_x < game->map_width && new_y >= 0
		&& new_y < game->map_height && game->map[new_y][new_x] != '1')
	{
		if (game->ondoor == 1)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->ondoor = 0;
		game->player_x = new_x;
		game->player_y = new_y;
		handle_tile_event(game, dx, dy);
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = 'P';
		game->move_count++;
		ft_putstr_fd(MOVES, 1);
		ft_putnbr_fd(game->move_count, 1);
		ft_putstr_fd("\n", 1);
	}
}
