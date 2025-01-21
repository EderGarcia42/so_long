/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:47 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/20 17:07:58 by edegarci         ###   ########.fr       */
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

# define MAP_ERROR "\nError:\nInvalid map format or configuration\n"
# define ERROR_01 "\nError:\nUsage: ./so_long <map_file>\n"
# define ERROR_02 "\nError:\nCould not read the map\n"
# define ERROR_03 "\nError:\nIs not rectangular\n"
# define ERROR_04 "\nError:\nIs not surrounded by walls\n"
# define ERROR_05 "\nError:\nDoes not contain the required components\n"
# define ERROR_06 "\nError:\nThere is no valid path in the map\n"
# define ERROR_07 "\nError:\nProblem to open the map\n"
# define ERROR_08 "\nError:\nMemory allocation error\n"
# define ERROR_09 "\nError:\nLine is empty\n"
# define ERROR_10 "\nError:\nFailed to initialize MiniLibX\n"
# define ERROR_11 "\nError:\nFailed to create a new window\n"
# define ERROR_12 "\nError:\nFailed to load image\n"
# define ERROR_13 "\nError:\nFailed to load player image\n"
# define ERROR_14 "\nError:\nFailed to load coin image\n"
# define ERROR_15 "\nError:\nFailed to load exit image\n"
# define ERROR_16 "\nError:\nFailed to load wall image\n"
# define ERROR_17 "\nError:\nFailed to load floor image\n"
# define VALID_MAP "\nThe map is valid!\n"

static int	open_map_file(const char *path);
static void	allocate_map(t_game *game);
void		read_map(t_game *game);
void		free_map(t_game *game);
void		ft_error(char *msg);
char		*read_line(int fd);
int			is_rectangular(t_game *game);
int			is_surrounded_by_walls(t_game *game);
int			is_valid_char(char c);
int			validate_components(t_game *game);
static int	find_player_position(t_game *game);
static void	flood_fill(char **map, int x, int y, int *components);
int			is_path_valid(t_game *game);
int			count_lines(const char *path);
void		print_map(t_game *game);

#endif
