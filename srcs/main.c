/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 15:03:07 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	main(int argc, char const *argv[])
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	args_parse(&env, argc, argv);
	start_so_long(&env);
	return (0);
}
