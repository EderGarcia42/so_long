/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:35:02 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/21 14:01:26 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
    char    *path;             // Path to the map
    char    **map;             // Game map
    int     x;                 // X position
    int     y;                 // Y position
    int     player_x;          // Player's X position
    int     player_y;          // Player's Y position
    int     player;            // Number of players (not used here, but part of the original structure)
    int     exit;              // Exit status (whether it's reached or not)
    int     coin;              // Number of coins
    void    *mlx;              // Pointer to the mlx instance
    void    *win;              // Pointer to the window
    int     map_width;         // Map width
    int     map_height;        // Map height
    void    *player_img;       // Player image
    void    *coin_img;         // Coin image
    void    *exit_img;         // Exit image
    void    *wall_img;         // Wall image
}           t_game;

#endif

