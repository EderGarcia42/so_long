/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/02/03 14:33:19 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	init_game_struct(t_game *game)
{
	game->path = NULL;
	game->map = NULL;
	game->x = 0;
	game->y = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player = 0;
	game->exit = 0;
	game->coin = 0;
	game->collected_coins = 0;
}

static int	handle_errors(t_game *game)
{
	if (!is_rectangular(game))
		return (ft_putstr_fd(ERROR_03, 2), free_map(game), 1);
	if (!is_surrounded_by_walls(game))
		return (ft_putstr_fd(ERROR_04, 2), free_map(game), 1);
	if (!validate_components(game))
		return (ft_putstr_fd(ERROR_05, 2), free_map(game), 1);
	if (!is_path_valid(game))
		return (ft_putstr_fd(ERROR_06, 2), free_map(game), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putstr_fd(ERROR_01, 2), 1);
	init_game_struct(&game);
	game.path = argv[1];
	read_map(&game);
	if (handle_errors(&game))
		return (1);
	ft_putstr_fd(VALID_MAP, 1);
	init_game(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, handle_exit, &game);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (0);
}
