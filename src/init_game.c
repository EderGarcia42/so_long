/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:31:44 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:21 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	load_image(t_game *game, char *path, void **img)
{
	*img = mlx_xpm_file_to_image(game->mlx, path, &game->map_width,
			&game->map_height);
	if (!*img)
		ft_error("Failed to load image");
}

void	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	win_width = ft_strlen(game->map[0]) * TILE_SIZE;
	win_height = game->y * TILE_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, win_width, win_height, WINDOW_TITLE);
	load_image(game, "assets/textures/P.xpm", &game->player_img);
	load_image(game, "assets/textures/C.xpm", &game->coin_img);
	load_image(game, "assets/textures/E.xpm", &game->exit_img);
	load_image(game, "assets/textures/1.xpm", &game->wall_img);
	load_image(game, "assets/textures/0.xpm", &game->floor_img);
}
