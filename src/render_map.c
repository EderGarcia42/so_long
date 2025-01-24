/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:03:12 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 15:00:10 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

char	*get_texture_path(char tile)
{
	char	*path;

	if (tile == '1')
		path = "assets/textures/1.xpm";
	else if (tile == 'P')
		path = "assets/textures/P.xpm";
	else if (tile == 'E')
		path = "assets/textures/E.xpm";
	else if (tile == 'C')
		path = "assets/textures/C.xpm";
	else
		path = "assets/textures/0.xpm";
	return (path);
}

void	render_tile(t_game *game, int x, int y, char tile)
{
	void	*img;
	int		tile_size;

	tile_size = TILE_SIZE;
	if (tile == '1')
		img = game->wall_img;
	else if (tile == 'P')
		img = game->player_img;
	else if (tile == 'E')
		img = game->exit_img;
	else if (tile == 'C')
		img = game->coin_img;
	else
		img = game->floor_img;
	mlx_put_image_to_window(game->mlx, game->win, img, x * tile_size, y
		* tile_size);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->y)
	{
		x = 0;
		while (x < ft_strlen(game->map[y]))
		{
			render_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
	render_tile(game, game->player_x, game->player_y, 'P');
}
