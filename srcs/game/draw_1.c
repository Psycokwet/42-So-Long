/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 15:02:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	find_asset_index_for(t_env *env, char id)
{
	int	i;

	i = 0;
	while (i < MAX_BLOCKS_PROPERTIES)
	{
		if (env->blocks_properties[i].id == id)
			return (i);
		i++;
	}
	return (-EXIT_FAILURE);
}

void	draw_asset(t_data *datas_target, t_data *datas_src,
t_coordinates start)
{
	t_coordinates	current;
	int32_t			color;

	current = (t_coordinates){0, 0};
	while (current.y < TILE_SIZE)
	{
		while (current.x < TILE_SIZE)
		{
			color = my_mlx_pixel_get(datas_src, (t_coordinates){current.x,
					current.y});
			if (color != (int32_t)MASK_T)
				my_mlx_pixel_put(datas_target, current.x + start.x, current.y
					+ start.y, color);
			current.x ++;
		}
		current.x = 0;
		current.y++;
	}
}

void	draw_block(t_env *env, t_data *datas, int id_asset,
t_coordinates start)
{
	if (id_asset < 0)
		return ;
	draw_asset(datas, &env->blocks_properties[id_asset].tex, start);
}

void	draw_rect(t_data *datas, t_coordinates start, t_coordinates end,
int color)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	while (y <= end.y)
	{
		while (x <= end.x)
		{
			my_mlx_pixel_put(datas, x, y, color);
			x++;
		}
		x = start.x;
		y++;
	}
}
