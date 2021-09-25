/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:09:50 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	should_update_axe(char map_case, char reject_move, int *current_axe,
	int *new_axe)
{
	if (map_case != reject_move && *current_axe != *new_axe)
	{
		*current_axe = *new_axe;
		return (true);
	}
	return (false);
}

static void	do_action(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_BLOCKS_PROPERTIES)
	{
		if (env->map_array.lines[env->current_pos.y][env->current_pos.x]
			== env->blocks_properties[i].id)
		{
			if (env->blocks_properties[i].effect)
				env->blocks_properties[i].effect(env, env->current_pos);
			return ;
		}
		i++;
	}
}

int	actually_run(t_env *env)
{
	t_coordinates	new_pos;

	new_pos = (t_coordinates){env->current_pos.x
		+ env->try_to_run_dir.x * RUN_STEP, env->current_pos.y
		+ env->try_to_run_dir.y * RUN_STEP};
	if ((should_update_axe(env->map_array.lines[new_pos.y][env->current_pos.x],
			AUTHORIZED_ON_MAP_WALL, &env->current_pos.y, &new_pos.y)
		| should_update_axe(env->map_array.lines[(int)(env->current_pos.y)]
		[(int)new_pos.x], AUTHORIZED_ON_MAP_WALL, &env->current_pos.x,
		&new_pos.x)) == true)
	{
		env->count++;
		do_action(env);
	}
	env->try_to_run_dir = (t_coordinates){0, 0};
	return (EXIT_SUCCESS);
}
