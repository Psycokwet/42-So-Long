/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/23 12:35:43 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	draw_asset(t_env *env, int id_asset, t_data *datas, t_coordinates start){
	// int x;
	// int y;

	// x = start.x;
	// y = start.y;
	// while(y <= end.y)
	// {
	// 	while(x <= end.x)
	// 	{
	// 		my_mlx_pixel_put(datas, x, y, color);
	// 		x++;
	// 	}
	// 	x = start.x;
	// 	y++;
	// }
}

void	draw_rect(t_data *datas, t_coordinates start, t_coordinates end, int color){
	int x;
	int y;

	x = start.x;
	y = start.y;
	while(y <= end.y)
	{
		while(x <= end.x)
		{
			my_mlx_pixel_put(datas, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
}

void	draw_water(t_data *datas, t_env *env)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){env->win_max_dimensions.x, env->win_max_dimensions.y}, COLOR_WATER);
}

void	draw_walls(t_data *datas, t_env *env)
{
}


void	print_img(t_env *env)
{
	int i;

	i = 0;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);

    env->imgs[i].img = mlx_new_image(env->mlx, env->win_max_dimensions.x, env->win_max_dimensions.y);
    env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img,	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, &env->imgs[i].endian);

	draw_water(&env->imgs[i], env);
	draw_walls(&env->imgs[i], env);

    mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);

}

