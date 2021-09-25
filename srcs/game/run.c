/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:09:44 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	run_up(t_env *env)
{
	env->try_to_run_dir.y -= QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_down(t_env *env)
{
	env->try_to_run_dir.y += QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_right(t_env *env)
{
	env->try_to_run_dir.x += QUOTIENT_MOVE;
	return (actually_run(env));
}

int	run_left(t_env *env)
{
	env->try_to_run_dir.x -= QUOTIENT_MOVE;
	return (actually_run(env));
}
