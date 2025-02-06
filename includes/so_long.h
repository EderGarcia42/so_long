/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:12:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/02/06 14:38:01 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "game.h"
# include "map_parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define TILE_SIZE 100
# define WINDOW_TITLE "so_long"

void		init_game(t_game *game);
void		render_tile(t_game *game, int x, int y, char tile);
void		render_map(t_game *game);
static char	*get_texture_path(char tile);
void		move_player(t_game *game, int dx, int dy);
int			handle_keypress(int keycode, t_game *game);
int			handle_exit(t_game *game);
int			collected_coins(t_game *game);
void		handle_tile_event(t_game *game, int dx, int dy);

#endif
