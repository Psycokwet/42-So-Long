/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/23 13:04:46 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static int	actually_run(t_env *env)
{
	printf("run\n");
	// printf("RUNNING %f:%f\n", env->current_pos.x, env->current_pos.y);
	// printf("DURECTION %f:%f\n", env->direction.x, env->direction.y);
// 	printf("try_to_run_dir %f:%f\n", env->try_to_run_dir.x, env->try_to_run_dir.y);


	t_coordinates new_pos = (t_coordinates){env->current_pos.x + env->try_to_run_dir.x * RUN_STEP, env->current_pos.y + env->try_to_run_dir.y * RUN_STEP};

	if(env->map_array.lines[(int)(new_pos.y + (env->try_to_run_dir.y * WALL_HIT_BOX))][(int)(env->current_pos.x)] != AUTHORIZED_ON_MAP_WALL) // (new_pos.x + (env->try_to_run_dir.x * WALL_HIT_BOX)))
	// {
		// printf("%c\n", env->map_array.lines[(int)(new_pos.y + (env->try_to_run_dir.y * WALL_HIT_BOX))]->line[(int)(env->current_pos.x)]);
		env->current_pos.y = new_pos.y;
	// }
	if(env->map_array.lines[(int)(env->current_pos.y)][(int)(new_pos.x + (env->try_to_run_dir.x * WALL_HIT_BOX))] != AUTHORIZED_ON_MAP_WALL) // 
		env->current_pos.x = new_pos.x;
	printf("RUNNING NEW POS %d:%d\n", env->current_pos.x, env->current_pos.y);
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
