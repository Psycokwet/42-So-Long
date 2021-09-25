/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:45:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	draw_water(t_env *env, t_data *datas)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){
		env->win_max_dimensions.x, env->win_max_dimensions.y},
		COLOR_WATER);
}

void	draw_objects(t_env *env, t_data *datas)
{
	t_coordinates	current;
	int				ret;

	ret = EXIT_SUCCESS;
	current = (t_coordinates){0, 0};
	while (current.y < env->map_array.height)
	{
		while (current.x < env->map_array.width)
		{
			if (env->map_array.lines[current.y][current.x]
					!= AUTHORIZED_ON_MAP_TILE)
				draw_block(env, datas, find_asset_index_for(env,
						env->map_array.lines[current.y][current.x]),
					(t_coordinates){current.x * TILE_SIZE, current.y
					* TILE_SIZE});
			current.x++;
		}
		current.y++;
		current.x = 0;
	}
}

void	draw_main(t_env *env, t_data *datas)
{
	draw_asset(datas, &env->main.tex, (t_coordinates){env->current_pos.x
		* TILE_SIZE, env->current_pos.y * TILE_SIZE});
}

void	print_img(t_env *env)
{
	int	i;

	i = 0;
	if (!env->win)
		return ;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);
	env->imgs[i].img = mlx_new_image(env->mlx, env->win_max_dimensions.x,
			env->win_max_dimensions.y);
	env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img,
			&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length,
			&env->imgs[i].endian);
	draw_water(env, &env->imgs[i]);
	draw_objects(env, &env->imgs[i]);
	draw_main(env, &env->imgs[i]);
	print_action_count(env);
	mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);
}
