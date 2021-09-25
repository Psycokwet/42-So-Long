/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 13:37:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	free_env(t_env *env)
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
	if (env->main.tex.img != NULL)
		mlx_destroy_image(env->mlx, env->main.tex.img);
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
}
