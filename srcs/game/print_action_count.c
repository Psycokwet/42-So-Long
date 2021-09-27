/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 13:30:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

#ifndef BONUS

void	print_action_count(t_env *env)
{
	if (env->last_count_printed == env->action_count)
		return ;
	env->last_count_printed = env->action_count;
	ft_putstr_fd("\r", 1);
	ft_putnbr_fd(env->action_count, 1);
}

#else

void	print_action_count(t_env *env)
{
	if (env->last_count_printed != env->action_count || !env->counter_string)
	{
		env->last_count_printed = env->action_count;
		if (env->counter_string)
			free(env->counter_string);
		env->counter_string = ft_itoa(env->action_count);
	}
	mlx_string_put(env->mlx, env->win, 5, 12, !(MASK_R | MASK_B | MASK_G),
		env->counter_string);
}

#endif
