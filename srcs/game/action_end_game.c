/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_end_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:47:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static void	exit_r(void *v_env)
{
	(void)v_env;
	printf("You lost...\n");
}

static void	exit_x(void *v_env)
{
	(void)v_env;
}

static void	exit_e(void *v_env)
{
	if (((t_env *)v_env)->collectibles == 0)
		printf("You won !\n");
	else
		exit_r(v_env);
}

void	init_end_game(t_env *env)
{
	env->end_game[ACTION_END_GAME_EXIT] = (t_end_game){false, &exit_e};
	env->end_game[ACTION_END_GAME_DEAD] = (t_end_game){false, &exit_r};
	env->end_game[ACTION_END_GAME_FORCE_QUIT] = (t_end_game){false, &exit_x};
}
