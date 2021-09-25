/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:48:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

#ifndef BONUS

void	print_action_count(t_env *env)
{
	if (env->last_count_printed == env->count)
		return ;
	ft_putstr_fd("\r", 1);
	ft_putnbr_fd(env->count, 1);
	env->last_count_printed = env->count;
}

#else

void	print_action_count(t_env *env)
{
	if (env->last_count_printed == env->count)
		return ;
	ft_putstr_fd("\r", 1);
	ft_putnbr_fd(env->count, 1);
	ft_putstr_fd("BONUS", 1);
	env->last_count_printed = env->count;
}

#endif
