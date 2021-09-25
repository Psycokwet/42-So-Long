/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 14:50:04 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static void	block_collectible_effect(void *v_env, t_coordinates coos)
{
	t_env	*env;

	env = (t_env *)v_env;
	env->collectibles--;
	env->map_array.lines[coos.y][coos.x] = AUTHORIZED_ON_MAP_TILE;
}

static void	block_patrol_effect(void *v_env, t_coordinates coos)
{
	t_env	*env;

	(void)coos;
	env = (t_env *)v_env;
	env->end_game[ACTION_END_GAME_DEAD].value = true;
}

static void	block_exit_effect(void *v_env, t_coordinates coos)
{
	t_env	*env;

	(void)coos;
	env = (t_env *)v_env;
	env->end_game[ACTION_END_GAME_EXIT].value = true;
}

int	init_blocks_properties(t_env *env)
{
	int	i;

	i = 0;
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_EXIT,
		EXIT_SRC, &block_exit_effect, (t_data){}};
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_WALL,
		WALL_SRC, NULL, (t_data){}};
	env->blocks_properties[i++] = (t_block_properties){
		AUTHORIZED_ON_MAP_COLLECTIBLE, COLLECTIBLE_SRC,
		&block_collectible_effect, (t_data){}};
	if (IF_BONUS)
		env->blocks_properties[i++] = (t_block_properties){
			AUTHORIZED_ON_MAP_PATROL, PATROL_SRC, &block_patrol_effect,
			(t_data){}};
	env->main = (t_main_character){MAIN_SRC, NULL, 0, (t_data){}};
	return (init_textures(env));
}
