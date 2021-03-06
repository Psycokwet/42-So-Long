/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/05/06 09:33:00 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libs/libft/libft.h"
# include "libs/minilibx-linux/mlx.h"
# include "libs/minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

# define RETURN_SUCCES			0
# define RETURN_FAILURE			1

# define EXIT_CODE_MAP_FOUND	2
# define EXIT_CODE_FOUND		1
# define EXIT_CODE_NOT_FOUND	0

# define EXIT_ARGS_FAILURE		2
# define EXIT_MLX_FAILURE		3
# define EXIT_NORMAL			0

# define B_SHIFT_T				24
# define B_SHIFT_R				16
# define B_SHIFT_G				8
# define B_SHIFT_B				0

# define MASK_T					0xFF000000
# define MASK_R					0x00FF0000
# define MASK_G					0x0000FF00
# define MASK_B					0x000000FF
# define BYTES_SIZE				8

# define MAP_ARG				"MAP.ber"
# define MAP_EXT				".ber"
# define USAGE					"Usage : MAP.ber"
# ifdef BONUS
#  define INSIDE_MAX_TYPE		5
#  define INSIDE					"0CEPR"
# else
#  define INSIDE_MAX_TYPE		4
#  define INSIDE					"0CEP"
# endif
# define WALL					"1"
# define AUTHORIZED_ON_MAP_WALL			'1'
# define AUTHORIZED_ON_MAP_TILE			'0'
# define AUTHORIZED_ON_MAP_POSITION		'P'
# define AUTHORIZED_ON_MAP_COLLECTIBLE	'C'
# define AUTHORIZED_ON_MAP_EXIT			'E'
# define AUTHORIZED_ON_MAP_PATROL		'R'

# define TILE_SIZE 16
# define COLOR_WATER 0x000000FF

# define REQUIRED_QT			3

# define MAX_DEGREES			360
# define FOV					90
# define ROTATE_DIV				50000
# define RUN_STEP				1
# define WALL_HIT_BOX			0.3
# define QUOTIENT_MOVE			1

# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_data;

// int				x;//i horizontale
// int				y;//j vertical
typedef struct s_coordinates
{
	int				x;
	int				y;
}	t_coordinates;

typedef struct s_map_array
{
	char				**lines;
	int					height;
	int					width;
}	t_map_array;

# define XK_ESCAPE						0xff1b
# define ESCAPE_ID						0

/* Move left, left arrow */
# define XK_LEFT						0xff51

/* Move left, left arrow */
# define ROTATE_LEFT_ID					1

/* Move right, right arrow */
# define XK_RIGHT						0xff53

/* Move right, right arrow */
# define ROTATE_RIGHT_ID				2

/* U+0061 LATIN SMALL LETTER A */
# define XK_LOW_AOW_A					0x0061

/* U+0061 LATIN SMALL LETTER A */
# define GO_LEFT_A_ID					3

/* U+0064 LATIN SMALL LETTER D */
# define XK_LOW_DOW_D					0x0064

/* U+0064 LATIN SMALL LETTER D */
# define GO_RIGTH_D_ID					4

/* U+0073 LATIN SMALL LETTER S */
# define XK_LOW_SOW_S					0x0073

/* U+0073 LATIN SMALL LETTER S */
# define GO_BACK_S_ID					5

/* U+0077 LATIN SMALL LETTER W */
# define XK_LOW_WOW_W					0x0077

/* U+0077 LATIN SMALL LETTER W */
# define GO_FRONT_W_ID					6
# define ACTUALLY_RUN					7

# define MAX_IMGS		7
# define MAX_TEX		4

# define EXIT_SRC			"./assets/exit.xpm"
# define WALL_SRC			"./assets/walls.xpm"
# define COLLECTIBLE_SRC	"./assets/collectible.xpm"
# define MAIN_SRC			"./assets/main.xpm"
# define PATROL_SRC			"./assets/patrol.xpm"

typedef struct s_block_properties
{
	char				id;
	char				*src;
	void				(*effect)(void *, t_coordinates block);
	t_data				tex;
}	t_block_properties;

# define MAX_FRAMES 7

typedef struct s_main_character
{
	char				*src;
	int					(*draw)(void *, t_coordinates start,
			int index_id_block);
	int					last_frame;
	t_data				tex;
}	t_main_character;

# ifdef BONUS
#  define MAX_BLOCKS_PROPERTIES 4
# else
#  define MAX_BLOCKS_PROPERTIES 3
# endif

# define ACTION_END_GAME_FORCE_QUIT	0
# define ACTION_END_GAME_DEAD		1
# define ACTION_END_GAME_EXIT		2
# define MAX_ACTION_END_GAME		3

typedef struct s_end_game
{
	int		value;
	void	(*fun)(void*);
}	t_end_game;

typedef struct s_env
{
	int					required[REQUIRED_QT];
	const char			*map_src;
	t_map_array			map_array;
	t_coordinates		try_to_run_dir;
	t_coordinates		current_pos;
	t_coordinates		win_max_dimensions;
	void				*mlx;
	void				*win;
	t_data				imgs[MAX_IMGS];
	int					last_count_printed;
	int					frame_count;
	int					action_count;
	int					collectibles;
	t_block_properties	blocks_properties[MAX_BLOCKS_PROPERTIES];
	t_main_character	main;
	t_end_game			end_game[MAX_ACTION_END_GAME];
	char				*counter_string;
}	t_env;

typedef struct s_parsing
{
	int		(*parser)(t_env *, const char **);
}	t_parsing;

/*
** ************************************************************************** **
** 									IMG                                       **
** ************************************************************************** **
*/

int32_t		my_mlx_pixel_get(t_data *datas, t_coordinates coos);
void		my_mlx_pixel_put(t_data *data, int x, int y, int32_t color);

/*
** ************************************************************************** **
** 									FILES                                     **
** ************************************************************************** **
*/

typedef struct s_map_parsing
{
	char const			authorized_chars;
	int					(*parser)(int i, int j, int index_parser, t_env *);
	int					single;
	int					replace;
}	t_map_parsing;

# ifdef BONUS
#  define MAX_MAP_PARSING 6
# else
#  define MAX_MAP_PARSING 5
# endif

int			id_pos(int i, int j, int index_parser, t_env *env);
int			id_required(int i, int j, int index_parser, t_env *env);
int			id_collectible(int i, int j, int index_parser, t_env *env);

static const t_map_parsing	g_map_parsings[MAX_MAP_PARSING] = {
	(t_map_parsing){AUTHORIZED_ON_MAP_POSITION, &id_pos, true, '0'},
	(t_map_parsing){AUTHORIZED_ON_MAP_COLLECTIBLE, &id_collectible,
			false, false},
	(t_map_parsing){AUTHORIZED_ON_MAP_EXIT, &id_required, true, false},
	(t_map_parsing){AUTHORIZED_ON_MAP_WALL, NULL, false, false},
	(t_map_parsing){AUTHORIZED_ON_MAP_TILE, NULL, false, false},
# ifdef BONUS
	(t_map_parsing){AUTHORIZED_ON_MAP_PATROL, NULL, false, false},
# endif
};

typedef struct s_map_rec_datas
{
	int		fd;
	char	*line;
	int		i;
	int		ret_gnl;
}	t_map_rec_datas;

void		args_parse(t_env *env, int argc, char const *argv[]);
void		free_array(char **splitted);
void		free_env(t_env *env);
int			parse_map_int(t_env *env, t_map_rec_datas datas);
int			parse_map(t_env *env);
int			parse_value(char const *arg);
void		set_src_map(t_env *env, char const *argv[]);
int			set_srcs(t_env *env, const char **params);
int			test_line_for_map(char *line, int index_line, t_env *env);

/*
** ************************************************************************** **
** 									COMMON                                    **
** ************************************************************************** **
*/

void		quit_app(t_env *env, const char *message, int code);

/*
** ************************************************************************** **
** 									GAME                                      **
** ************************************************************************** **
*/

void		start_so_long(t_env *env);
void		draw_asset(t_data *datas_target, t_data *datas_src,
				t_coordinates start_target, t_coordinates start_src);
void		draw_rect(t_data *datas, t_coordinates start, t_coordinates end,
				int color);
void		draw_water(t_env *env, t_data *datas);
void		print_img(t_env *env);
int			init_blocks_properties(t_env *env);
void		init_end_game(t_env *env);
void		init_imgs(t_env *env);
int			init_texture(t_env *env, char *src, t_data *tex);
int			init_textures(t_env *env);
void		draw_block(t_env *env, t_data *datas, int id_asset,
				t_coordinates start);
void		print_action_count(t_env *env);
int			find_asset_index_for(t_env *env, char id);

typedef struct s_actions
{
	int		keycode;
	int		(*fun)(t_env *);
}	t_action;

int			actually_run(t_env *env);
int			run_up(t_env *env);
int			run_down(t_env *env);
int			run_right(t_env *env);
int			run_left(t_env *env);
int			quit_game(t_env *env);

# define MAX_ACTIONS	5

static const t_action		g_actions[MAX_ACTIONS] = {
	(t_action){XK_ESCAPE, &quit_game},
	(t_action){XK_LOW_AOW_A, &run_left},
	(t_action){XK_LOW_DOW_D, &run_right},
	(t_action){XK_LOW_SOW_S, &run_down},
	(t_action){XK_LOW_WOW_W, &run_up},
};

#endif
