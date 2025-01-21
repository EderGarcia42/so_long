/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:12:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/16 13:49:08 by edegarci         ###   ########.fr       */
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

# define TILE_SIZE 100
# define WINDOW_TITLE "so_long"

void		init_game(t_game *game);
void		start_game(t_game *game);
void		render_map(t_game *game);
static char	*get_texture_path(char tile);
void		render_tile(t_game *game, int x, int y, char tile);
int			handle_keypress(int keycode, t_game *game);
int			handle_exit(t_game *game);

#endif
