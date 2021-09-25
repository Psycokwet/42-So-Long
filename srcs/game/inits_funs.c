/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_funs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:19:29 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	init_imgs(t_env *env)
{
	int	i;

	i = -1;
	while (i++ < MAX_IMGS - 1)
		env->imgs[i] = (t_data){NULL, NULL, -1, -1, -1, -1, -1};
}

int	init_texture(t_env *env, char *src, t_data *tex)
{
	tex->img = mlx_xpm_file_to_image(env->mlx,
			src, &tex->w, &tex->h);
	if (!tex->img)
		return (-EXIT_FAILURE);
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bits_per_pixel, &tex->line_length,
			&tex->endian);
	if (!tex->addr)
		return (-EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_BLOCKS_PROPERTIES)
	{
		if (init_texture(env, env->blocks_properties[i].src,
				&env->blocks_properties[i].tex) < EXIT_SUCCESS)
			return (-EXIT_FAILURE);
		i++;
	}
	if (init_texture(env, env->main.src, &env->main.tex) < EXIT_SUCCESS)
		return (-EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
