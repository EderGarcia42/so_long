/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/21 14:25:39 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_parser.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	game.path = argv[1];
	game.x = 0;
	game.y = 0;
	game.player = 0;
	game.exit = 0;
	game.coin = 0;
	read_map(&game);
	if (handle_errors(&game))
		return (1);
	ft_putstr_fd(VALID_MAP, 1);
	init_game(&game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}
