/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 07:57:05 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int		quit_game(t_env *env)
{
	printf("QUITTING ! \n");
	// mlx_destroy_image(env->mlx, game->screen.ptr);
	mlx_destroy_window(env->mlx, env->win);
	// free_env(env);
	return (EXIT_SUCCESS);
}
