/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/20 10:57:45 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	free_env(t_env *env)
{
	int i;

	i = 0;
	if (env->map_array.lines)
	{
		i = 0;
		while (i < env->map_array.height)
		{
			if (env->map_array.lines[i] != NULL)
				free(env->map_array.lines[i]);
			i++;
		}
		free(env->map_array.lines);
	}
	env->map_src = NULL;

	i = 0;
	while (i < MAX_IMGS)
	{
		if (env->imgs[i].img != NULL)
			mlx_destroy_image(env->mlx, env->imgs[i].img);
		i++;
	}
	i = 0;
	printf("Alive\n");
	while (i < MAX_TEX)
	{
		if (env->textures[i].img != NULL)
			mlx_destroy_image(env->mlx, env->textures[i].img);
		i++;
	}
	printf("Alive\n");
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
	printf("Alive\n");
}
