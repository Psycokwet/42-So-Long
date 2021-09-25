/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/25 12:02:02 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"
#include "get_next_line.h"

int	simple_free_and_return(char *line, int code)
{
	if (line)
		free(line);
	return (code);
}

int	parse_map_int1(t_env *env, t_map_rec_datas *datas, int line_size)
{
	char		*next_line;

	next_line = NULL;
	datas->ret_gnl = get_next_line(datas->fd, &next_line);
	if (datas->ret_gnl >= 0)
	{
		if (parse_map_int(env, (t_map_rec_datas)
				{datas->fd, next_line, datas->i + 1, datas->ret_gnl})
			< EXIT_SUCCESS)
			return (simple_free_and_return(datas->line, -EXIT_FAILURE));
		if (env->map_array.width == -1)
			env->map_array.width = line_size;
		if (env->map_array.width != line_size)
			return (-EXIT_FAILURE);
		env->map_array.lines[datas->i] = datas->line;
	}
	return (EXIT_SUCCESS);
}

int	parse_map_int(t_env *env, t_map_rec_datas datas)
{
	int			line_size;

	line_size = 0;
	if (!datas.line)
		return (-EXIT_FAILURE);
	line_size = test_line_for_map(datas.line, datas.i, env);
	if (line_size < EXIT_SUCCESS)
		return (simple_free_and_return(datas.line, -EXIT_FAILURE));
	else if (datas.line[0])
		return (parse_map_int1(env, &datas, line_size));
	else if (datas.ret_gnl == 0)
	{
		env->map_array.lines = (char **)malloc(sizeof(char *) * (datas.i));
		if (env->map_array.lines == NULL)
			return (-EXIT_FAILURE);
		free(datas.line);
		env->map_array.height = datas.i;
	}
	else
		return (simple_free_and_return(datas.line, -EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int	open_map(t_env *env)
{
	int		fd;

	fd = open(env->map_src, O_RDONLY);
	if (fd < 0)
	{
		printf("failed to open the map for reading\n");
		exit(EXIT_ARGS_FAILURE);
	}
	return (fd);
}

int	parse_map(t_env *env)
{
	int		fd;
	char	*line;
	int		ret;

	ret = -RETURN_FAILURE;
	fd = open_map(env);
	env->map_array.width = -1;
	env->map_array.height = -1;
	line = NULL;
	if (get_next_line(fd, &line) != EXIT_READ_OPEN)
	{
		if (line)
			free(line);
		get_next_line(-1, NULL);
		printf("Map is too short or there is an error while opening it\n");
		exit(EXIT_ARGS_FAILURE);
	}
	ret = parse_map_int(env, (t_map_rec_datas){fd, line, 0, 1});
	if (ret < RETURN_SUCCES)
		get_next_line(-1, NULL);
	close(fd);
	return (ret);
}
