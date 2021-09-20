/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_src_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/19 23:30:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	set_src_map(t_env *env, char const *argv[])
{
	int s1;
	int s2;

	s1 = ft_strlen(MAP_EXT);
	s2 = ft_strlen(argv[1]);
	if (ft_memcmp(MAP_EXT, argv[1] + s2 - s1, s1) != 0)
	{
		printf("Error, the first argument has a wrong extension fit.\n %s",
		USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	env->map_src = argv[1];
}
