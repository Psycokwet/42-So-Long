/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/27 13:33:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static void	free_env_int(t_env *env)
{
	int	i;

	if (env->map_array.lines)
	{
		i = -1;
		while (++i < env->map_array.height)
			if (env->map_array.lines[i] != NULL)
				free(env->map_array.lines[i]);
		free(env->map_array.lines);
	}
	i = -1;
	while (++i < MAX_IMGS)
		if (env->imgs[i].img != NULL)
			mlx_destroy_image(env->mlx, env->imgs[i].img);
	i = -1;
	while (++i < MAX_BLOCKS_PROPERTIES)
		if (env->blocks_properties[i].tex.img != NULL)
			mlx_destroy_image(env->mlx, env->blocks_properties[i].tex.img);
}

void	free_env(t_env *env)
{
	free_env_int(env);
	if (env->main.tex.img != NULL)
		mlx_destroy_image(env->mlx, env->main.tex.img);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	if (env->counter_string)
		free(env->counter_string);
}
