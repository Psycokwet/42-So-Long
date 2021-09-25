/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:20:22 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

#define MY_DESTROY_NOTIFY		33

int	key_press(int keycode, t_env *env)
{
	int	i;

	i = -1;
	while (i++ < MAX_ACTIONS)
	{
		if (keycode == g_actions[i].keycode)
		{
			if (g_actions[i].fun)
				g_actions[i].fun(env);
			break ;
		}
	}
	return (keycode);
}

int	close_window(t_env *env)
{
	env->end_game[ACTION_END_GAME_FORCE_QUIT].value = true;
	return (0);
}

int	game_loop(t_env *env)
{
	int	i;

	if (env->win)
		print_img(env);
	i = 0;
	while (i < MAX_ACTION_END_GAME)
	{
		if (env->end_game[i].value == true)
		{
			printf("\n");
			if (env->end_game[i].fun)
				env->end_game[i].fun(env);
			g_actions[0].fun(env);
			break ;
		}
		i++;
	}
	return (0);
}

int	correct_max_dimension(t_env *env)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(env->mlx, &sizex, &sizey);
	if (sizex < (env->map_array.width * TILE_SIZE))
		return (-EXIT_FAILURE);
	if (sizey < (env->map_array.height * TILE_SIZE))
		return (-EXIT_FAILURE);
	env->win_max_dimensions.x = env->map_array.width * TILE_SIZE;
	env->win_max_dimensions.y = env->map_array.height * TILE_SIZE;
	return (EXIT_SUCCESS);
}

void	start_so_long(t_env *env)
{
	init_imgs(env);
	init_end_game(env);
	env->mlx = mlx_init();
	if (correct_max_dimension(env) < EXIT_SUCCESS)
		quit_app(env, "The map is too big for the screen", -EXIT_FAILURE);
	if (init_blocks_properties(env) < EXIT_SUCCESS)
		quit_app(env, "Error encountered while initializing \
textures, the files may not exist", -EXIT_FAILURE);
	env->win = mlx_new_window(env->mlx, env->win_max_dimensions.x,
			env->win_max_dimensions.y, "So long !");
	print_img(env);
	mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	mlx_hook(env->win, MY_DESTROY_NOTIFY, StructureNotifyMask, close_window,
		env);
	mlx_loop_hook(env->mlx, game_loop, env);
	mlx_loop(env->mlx);
	free_env(env);
}
