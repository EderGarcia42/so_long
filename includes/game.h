/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:35:02 by edegarci          #+#    #+#             */
/*   Updated: 2025/02/06 11:49:01 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	char	*path;				// Path to the map
	char	**map;				// Game map
	int		x;					// X position
	int		y;					// Y position
	int		player_x;			// Player's X position
	int		player_y;			// Player's Y position
	int		player;				// Player exists
	int		exit;				// Exit exists
	int		coin;				// Number of coins
	void	*mlx;				// Pointer to the mlx instance
	void	*win;				// Pointer to the window
	int		map_width;			// Map width
	int		map_height;			// Map height
	void	*player_img;		// Player image
	void	*coin_img;			// Coin image
	void	*exit_img;			// Exit image
	void	*wall_img;			// Wall image
	void	*floor_img;			// Floor image
	int		player_dx;			// Dirección X movement
	int		player_dy;			// Direction Y movement
	int		total_coins;		// Total coins
	int		collected_coins;	// Collected coins
	int		move_count;			// Player movement count
	int		ondoor;				// Player on door
}	t_game;

#endif
