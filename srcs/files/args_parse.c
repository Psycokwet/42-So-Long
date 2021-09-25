/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 13:30:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	is_inside(char c)
{
	int	i;

	i = 0;
	while (i < INSIDE_MAX_TYPE)
	{
		if (INSIDE[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_for_holes(t_env *env)
{
	int	line;
	int	column;

	line = 0;
	column = -1;
	while (env->map_array.height > line)
	{
		while (env->map_array.width > ++column)
			if ((is_inside(env->map_array.lines[line][column]) == 1) &&
			((line > 0 && is_inside(env->map_array.lines[line - 1][column
			]) == 0 && env->map_array.lines[line - 1][column] != '1') || (
			line + 1 < env->map_array.height && is_inside(env->map_array.lines[
			line + 1][column]) == 0 && env->map_array.lines[line + 1]
			[column] != '1') || (column > 0 && is_inside(env->map_array.
			lines[line][column - 1]) == 0 && env->map_array.lines[line]
			[column - 1] != '1') || (column + 1 <= env->map_array.width
			&& is_inside(env->map_array.lines[line][column + 1])
			== 0 && env->map_array.lines[line][column + 1] != '1')))
				return (-EXIT_FAILURE);
		column = -1;
		line++;
	}
	return (EXIT_SUCCESS);
}

int	check_min_requirements(t_env *env)
{
	int	i;

	i = 0;
	while (i < REQUIRED_QT)
	{
		if (env->required[i] == false)
			return (-EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	args_parse(t_env *env, int argc, char const *argv[])
{
	const char	*name;

	name = argv[0];
	if (argc > 2)
	{
		printf("Error, there is too much arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	if (argc < 2)
	{
		printf("Error\nThere is not enough arguments.\n%s\n", USAGE);
		exit(EXIT_ARGS_FAILURE);
	}
	set_src_map(env, argv);
	if (parse_map(env) < RETURN_SUCCES)
		quit_app(env, "While reading the file. There may be an \
error in the content of the map", -EXIT_ARGS_FAILURE);
	if (check_map_for_holes(env) < EXIT_SUCCESS)
		quit_app(env, "The map contains holes", -EXIT_FAILURE);
	if (check_min_requirements(env) < EXIT_SUCCESS)
		quit_app(env, "Lacking required minimum elements on map",
			-EXIT_FAILURE);
}
