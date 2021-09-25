NAME				=	so_long
BONUS				=	bonus
NAME_BONUS 			= so_long_bonus
MAKE_LIBFT			=	makelibft
LIBSPATH			=	libs/
LIBFTPATH			=	libft/
LIBFT_AR			=	libft.a
LIBMLX_AR			= 	libmlx.a

SRC_PATH			= ./srcs/
OBJ_PATH			= bin/
LIBFT_PATH			= libft/
LIBMLX_UNIX_PATH	= minilibx-linux/

COLORS_PATH 	= colors/
IMG_PATH		= img/
FILES_PATH		= files/
COMMON_PATH		= common/
GAME_PATH		= game/

OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(COLORS_PATH) 	\
													$(IMG_PATH) 	\
													$(COMMON_PATH) 	\
													$(GAME_PATH) 	\
													$(FILES_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	main.h
SRC_FILES					=	main.c
COLORS_FILES				=	get_opposite.c 	\
								add_shade.c 	\
								create_trgb.c
IMG_FILES					=	my_mlx_pixel_put.c
FILES_FILES					=	args_parse.c	\
								free_array.c\
								free_env.c\
								get_next_line_utils.c\
								get_next_line.c\
								parse_map.c\
								parse_value.c\
								set_src_map.c\
								test_line_for_map.c
COMMON_FILES				=	quit_app.c 
GAME_FILES					=	draw.c \
								quit_game.c \
								run.c \
								start_cub_3d.c


SRC_FILES += $(addprefix $(COLORS_PATH), $(COLORS_FILES))
SRC_FILES += $(addprefix $(IMG_PATH), $(IMG_FILES))
SRC_FILES += $(addprefix $(FILES_PATH), $(FILES_FILES))
SRC_FILES += $(addprefix $(COMMON_PATH), $(COMMON_FILES))
SRC_FILES += $(addprefix $(GAME_PATH), $(GAME_FILES))


OBJREGULAR_FILES	= 	$(SRC_FILES:.c=.o)			## get all .o names from .c names

OBJ_FILES = $(OBJREGULAR_FILES)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			=	clang

CFLAGS		+=	-W -Wall -Wextra -D BUFFER_SIZE=32 -g3 #-Werror  -pedantic 		## '+=' allow to keep default flags.

LDFLAGS		=	-L$(addprefix $(LIBSPATH), $(LIBFTPATH)) -lft -L$(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)) -lm -lbsd -lX11 -lXext $(addprefix $(addprefix $(LIBSPATH), $(LIBMLX_UNIX_PATH)), $(LIBMLX_AR))

RM			= 	rm -f

OS			= $(shell uname)

ifdef WITH_BONUS
	CFLAGS	+= -DBONUS
	NAME	=	$(NAME_BONUS)
endif

all					:	 $(OBJ_PATHS_INIT) $(MAKE_LIBFT) $(NAME)


$(addprefix $(LIBSPATH), $(LIBFT_PATH))  		:
	git clone https://github.com/Psycokwet/libft.git $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(MAKE_LIBFT)		: $(addprefix $(LIBSPATH), $(LIBFT_PATH))
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH))

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)  $(INC) 

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME)			: 	$(OBJ)  $(addprefix $(LIBSPATH), $(addprefix $(LIBFTPATH),$(LIBFT_AR)))
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)  $(INC) 

$(BONUS)		:
	$(MAKE) WITH_BONUS=1 all

		
clean_local		:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)

clean			:									## delete all .o
	$(RM) $(OBJ) $(OBJBONUS)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) clean	

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAMETEST) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(addprefix $(LIBSPATH), $(LIBFT_PATH)) fclean					

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 