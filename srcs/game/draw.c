/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/24 11:29:02 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"


// void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int		get_tex_color(t_env *env)
// {
// 	int color;

// 	color = 0;
// 	if (env->rndr->texposx >= 0 && env->rndr->texposx < env->rndr->tex->h
// 	&& env->rndr->texx >= 0 && env->rndr->texx < env->rndr->tex->w)
// 		color = *(int*)(env->rndr->tex->addr
// 		+ (4 * env->rndr->tex->w * (int)env->rndr->texy)
// 		+ (4 * (int)env->rndr->texx));
// 	return (color);
// }

#define PIXEL_SIZE 4
int get_pixel_color(t_data *datas, t_coordinates coos)
{
// 	printf("stats %d, %d, %d, %d\n", datas->bits_per_pixel, datas->endian, datas->line_length/4, 
// (int*)	(datas->addr + (coos.y * datas->line_length + coos.x * (datas->bits_per_pixel / 8))));//(coos.y * datas->line_length)  + (coos.x * PIXEL_SIZE)]);

		printf("get_pixel_color %p %d, %d, %d\n",datas->addr, datas->bits_per_pixel, datas->endian, datas->line_length);
	return (datas->addr + (coos.y * datas->line_length + coos.x * (datas->bits_per_pixel/8 )));
	// return MASK_R;
}

int find_asset_index_for(t_env *env, char id)
{
	int i;

	i = 0;
	while (i < MAX_BLOCKS_PROPERTIES)
	{
		if (env->blocks_properties[i].id == id)
			return i;
		i++;
	}
	return (-EXIT_FAILURE);
}

void	draw_asset(t_env *env, t_data *datas, int id_asset, t_coordinates start)
{
	t_coordinates current;

	current = (t_coordinates){0, 0};
	if (id_asset < 0)
		return ;
	// printf("ASSET ID : %d for \n", id_asset);
	printf("ASSET ID : %d for %c \n", id_asset, env->blocks_properties[id_asset].id);
	while(current.y <= TILE_SIZE)
	{
		while(current.x <= TILE_SIZE)
		{
			my_mlx_pixel_put(datas, current.x + start.x, current.y + start.y, get_pixel_color(&env->blocks_properties[id_asset].tex, (t_coordinates){current.x, current.y}));
			current.x ++;
		}
		current.x = 0;
		current.y++;
	}
}

void	draw_rect(t_data *datas, t_coordinates start, t_coordinates end, int color)
{
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

void	draw_water(t_env *env, t_data *datas)
{
	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){env->win_max_dimensions.x, env->win_max_dimensions.y}, COLOR_WATER);
}

void	draw_objects(t_env *env, t_data *datas)
{
	t_coordinates current;
	int ret = EXIT_SUCCESS;

	current = (t_coordinates){0, 0};
	while (current.y < env->map_array.height)
	{
		while (current.x < env->map_array.width)
		{
			if (env->map_array.lines[current.y][current.x] != AUTHORIZED_ON_MAP_TILE)
				draw_asset(env, datas, find_asset_index_for(env, env->map_array.lines[current.y][current.x]), (t_coordinates){current.x * TILE_SIZE, current.y * TILE_SIZE});
			current.x++;
		}
		current.y++;
		current.x = 0;
	}
}

void	print_img(t_env *env)
{
	int i;

	i = 0;
	if (env->imgs[i].img != NULL)
		mlx_destroy_image(env->mlx, env->imgs[i].img);

    env->imgs[i].img = mlx_new_image(env->mlx, env->win_max_dimensions.x, env->win_max_dimensions.y);
    env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img,	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, &env->imgs[i].endian);

	draw_water(env, &env->imgs[i]);
	draw_objects(env, &env->imgs[i]);

    mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);

}

