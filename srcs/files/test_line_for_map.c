/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_line_for_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/23 13:06:45 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "get_next_line.h"

int		id_pos(int i_width, int i_height, int index_parser, t_env *env)
{
	id_required(i_width, i_height, index_parser, env);
	env->current_pos = (t_coordinates){i_width, i_height};
	printf("RUNNING NEW POS %d:%d\n", env->current_pos.x, env->current_pos.y);

	return (EXIT_SUCCESS);
}

int		id_required(int i_width, int i_height, int index_parser, t_env *env)
{
	(void)i_width;
	(void)i_height;
	if (env->required[index_parser] == false){
		env->required[index_parser] = true;
		return (EXIT_SUCCESS);
	}
	if(g_map_parsings[index_parser].single == false)
		return (EXIT_SUCCESS);
	return (-EXIT_FAILURE);
}

int	test_line_for_map_int(char *line, t_env *env, int i_height, int i_width)
{
	int		index_parser;
	int		ret;

	ret = false;
	index_parser = 0;
	while (index_parser < MAX_MAP_PARSING)
	{
		if (g_map_parsings[index_parser].authorized_chars == line[i_width])
		{
			ret = true;
			if (g_map_parsings[index_parser].parser)
				if (g_map_parsings[index_parser].parser(i_width, i_height, index_parser, env)
				< EXIT_SUCCESS)
					return (false);
			if (g_map_parsings[index_parser].replace != false)
				line[i_width] = g_map_parsings[index_parser].replace;
			break ;
		}
		index_parser++;
	}
	return (ret);
}

int		test_line_for_map(char *line, int index_line, t_env *env)
{
	int		i_width;
	int		ret;

	i_width = 0;
	ret = false;
	while (line[i_width])
	{
		ret = test_line_for_map_int(line, env, index_line, i_width);
		if (ret == false)
			return (-EXIT_FAILURE);
		i_width++;
	}
	return (i_width);
}
