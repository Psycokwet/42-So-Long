/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/24 14:29:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int should_update_axe(char map_case, char reject_move, int *current_axe, int *new_axe)
{

	if(map_case != reject_move && *current_axe != *new_axe)
	{
		*current_axe = *new_axe;
		return (true);
	}
	return (false);
}

static int	actually_run(t_env *env)
{
	// printf("run\n");
	t_coordinates new_pos = (t_coordinates){env->current_pos.x + env->try_to_run_dir.x * RUN_STEP, env->current_pos.y + env->try_to_run_dir.y * RUN_STEP};

	if ((should_update_axe(env->map_array.lines[new_pos.y][env->current_pos.x], AUTHORIZED_ON_MAP_WALL, &env->current_pos.y, &new_pos.y) 
	| should_update_axe(env->map_array.lines[(int)(env->current_pos.y)][(int)new_pos.x], AUTHORIZED_ON_MAP_WALL, &env->current_pos.x, &new_pos.x)) == true)
		env->count++;
	// printf("RUNNING NEW POS %d:%d::%d\n", env->current_pos.x, env->current_pos.y, env->count);
	env->try_to_run_dir = (t_coordinates){0, 0};
	return (EXIT_SUCCESS);
}

int	run_up(t_env *env)
{
	env->try_to_run_dir.y-= QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_down(t_env *env)
{
	env->try_to_run_dir.y+= QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_right(t_env *env)
{
	env->try_to_run_dir.x+= QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_left(t_env *env)
{
	env->try_to_run_dir.x-= QUOTIENT_MOVE;
	return (actually_run(env));
}
