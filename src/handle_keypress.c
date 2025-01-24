/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:33:14 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 14:32:24 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	handle_keypress(int keycode, t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	else if (keycode == KEY_ESC)
		handle_exit(game);
	if (game->map[game->player_y][game->player_x] == 'E')
		game->map[game->player_y][game->player_x] = 'P';
	render_map(game);
	return (0);
}
