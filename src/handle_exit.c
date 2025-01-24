/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:54:55 by edegarci          #+#    #+#             */
/*   Updated: 2025/01/24 12:59:36 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/so_long.h"
#include "../libs/libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	handle_exit(t_game *game)
{
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
