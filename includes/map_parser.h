/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:47 by edegarci          #+#    #+#             */
/*   Updated: 2025/02/03 15:49:17 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "../libs/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "game.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NC "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

# define MAP_ERROR RED "\nError:\nInvalid map format or configuration\n" NC
# define ERROR_01 RED "\nError:\nUsage: ./so_long <map_file>\n" NC
# define ERROR_02 RED "\nError:\nCould not read the map\n" NC
# define ERROR_03 RED "\nError:\nIs not rectangular\n" NC
# define ERROR_04 RED "\nError:\nIs not surrounded by walls\n" NC
# define ERROR_05 RED "\nError:\nDoes not contain the required components\n" NC
# define ERROR_06 RED "\nError:\nThere is no valid path in the map\n" NC
# define ERROR_07 RED "\nError:\nProblem to open the map\n" NC
# define ERROR_08 RED "\nError:\nMemory allocation error\n" NC
# define ERROR_09 RED "\nError:\nLine is empty\n" NC
# define ERROR_10 RED "\nError:\nFailed to initialize MiniLibX\n" NC
# define ERROR_11 RED "\nError:\nFailed to create a new window\n" NC
# define ERROR_12 RED "\nError:\nFailed to load image\n" NC
# define ERROR_13 RED "\nError:\nFailed to load player image\n" NC
# define ERROR_14 RED "\nError:\nFailed to load coin image\n" NC
# define ERROR_15 RED "\nError:\nFailed to load exit image\n" NC
# define ERROR_16 RED "\nError:\nFailed to load wall image\n" NC
# define ERROR_17 RED "\nError:\nFailed to load floor image\n" NC
# define ERROR_18 RED "\nError:\nMap contains empty line\n" NC
# define VALID_MAP GREEN "\nLoading map...\nThe map is valid!\n" NC
# define MOVES YELLOW "\nTotal moves:\n" NC
# define COINS GREEN "\nTotal food eaten:\n" NC
# define WIN GREEN "\n\nYOU ATE ALL THE FOOD!\nCONGRATULATIONS!\nClosing map...\n" NC
# define WARNING RED "\n\nWAIT!!!\nYou need to eat all the food first!\n" NC

static int	open_map_file(const char *path);
static void	allocate_map(t_game *game);
void		read_map(t_game *game);
char		*read_line(int fd);
void		free_map(t_game *game);
void		ft_error(char *msg);
int			is_rectangular(t_game *game);
int			is_surrounded_by_walls(t_game *game);
int			is_valid_char(char c);
int			validate_components(t_game *game);
static int	find_player_position(t_game *game);
static void	flood_fill(char **map, int x, int y, int *components);
int			is_path_valid(t_game *game);
int			count_lines(const char *path);
void		count_coins(t_game *game);
void		count_total_coins(t_game *game);
void		print_map(t_game *game);
void		free_resources(t_game *game);
int			handle_exit(t_game *game);
static void	init_game_struct(t_game *game);
int			validate_map(t_game *game);

#endif
