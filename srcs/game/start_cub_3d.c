/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/19 23:09:31 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

// #define DestroyNotify		33




// void	rotation(t_cartesian_vector *vector, float angle)
// {
// 	float	x;
// 	float	y;

// 	x = vector->dir.x;
// 	y = vector->dir.y;
// 	vector->dir.x = x * cos(angle) - y * sin(angle);
// 	vector->dir.y = x * sin(angle) + y * cos(angle);
// }


// void	draw_rect(t_data *datas, t_coordinates start, t_coordinates end, int color){
// 	int x;
// 	int y;

// 	x = start.x;
// 	y = start.y;
// 	while(y <= end.y)
// 	{
// 		while(x <= end.x)
// 		{
// 			my_mlx_pixel_put(datas, x, y, color);
// 			x++;
// 		}
// 		x = start.x;
// 		y++;
// 	}
// }

// void	draw_ceiling_floor(t_data *datas, t_env *env)
// {
// 	draw_rect(datas, (t_coordinates){0, 0}, (t_coordinates){env->r.width - 1, env->r.height / 2}, env->g_colors[CODE_CEILING].color);
// 	draw_rect(datas, (t_coordinates){0, env->r.height / 2}, (t_coordinates){env->r.width - 1, env->r.height - 1}, env->g_colors[CODE_FLOOR].color);
// }

// void	draw_walls(t_data *datas, t_env *env)
// {
// 	int current_x;
// 	float ratio;
// 	int half_width_x;
// 	t_cartesian_vector char_direction;
// 	env->plane.x = 0;
// 	env->plane.x = 0.66;

// 	half_width_x = env->r.width/2;
// 	current_x = 0;
// 	while(current_x < env->r.width)
// 	{
// 		ratio = (current_x - (float)half_width_x) / (float)half_width_x;
		
// 		printf("cc %f %d\n", ratio, current_x);
// 		printf("dir %f %f\n", env->direction.x * ratio, env->direction.y * ratio);
// 		float cameraX = 2 * current_x / (float) env->r.width - 1; //x-coordinate in camera space
// 		float rayDirX = env->direction.x + env->plane.x * cameraX;
// 		float rayDirY = env->direction.y + env->plane.x * cameraX;
// 		// float deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
// 		// float deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
// 		// char_direction.dir.x = cos(env->fov_angle)/2 + cos(env->fov_angle - 0.25) * ratio;
// 		// dir.y = cos();


// 		//which box of the map we're in
// 		int mapX = (int) env->current_pos.x;
// 		int mapY = (int) env->current_pos.y;

// 		//length of ray from current position to next x or y-side
// 		float sideDistX;
// 		float sideDistY;

// 		//length of ray from one x or y-side to next x or y-side

// 		// Alternative code for deltaDist in case division through zero is not supported
// 		float deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : abs(1 / rayDirX));
// 		float deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : abs(1 / rayDirY));
// 		// float deltaDistX = abs(1 / rayDirX);
// 		// float deltaDistY = abs(1 / rayDirY);
// 		float perpWallDist;

// 		//what direction to step in x or y-direction (either +1 or -1)
// 		int stepX;
// 		int stepY;

// 		int hit = 0; //was there a wall hit?
// 		int side; //was a NS or a EW wall hit?

// 		//calculate step and initial sideDist
// 		if (rayDirX < 0)
// 		{
// 			stepX = -1;
// 			sideDistX = (env->current_pos.x - mapX) * deltaDistX;
// 		}
// 		else
// 		{
// 			stepX = 1;
// 			sideDistX = (mapX + 1.0 - env->current_pos.x) * deltaDistX;
// 		}
// 		if (rayDirY < 0)
// 		{
// 			stepY = -1;
// 			sideDistY = (env->current_pos.y - mapY) * deltaDistY;
// 		}
// 		else
// 		{
// 			stepY = 1;
// 			sideDistY = (mapY + 1.0 - env->current_pos.x) * deltaDistY;
// 		}
// 		//perform DDA
// 		while (hit == 0)
// 		{
// 			//jump to next map square, OR in x-direction, OR in y-direction
// 			if (sideDistX < sideDistY)
// 			{
// 			sideDistX += deltaDistX;
// 			mapX += stepX;
// 			side = 0;
// 			}
// 			else
// 			{
// 			sideDistY += deltaDistY;
// 			mapY += stepY;
// 			side = 1;
// 			}
// 			//Check if ray has hit a wall
// 			if (env->map_array.lines[mapY]->line[mapX] > 0) hit = 1;
// 		}

// 		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
// 		if (side == 0) perpWallDist = (mapX - env->current_pos.x + (1 - stepX) / 2) / rayDirX;
// 		else           perpWallDist = (mapY - env->current_pos.y + (1 - stepY) / 2) / rayDirY;

// 		//Calculate height of line to draw on screen
// 		int lineHeight = (int)(env->r.height / perpWallDist);

// 		//calculate lowest and highest pixel to fill in current stripe
// 		int drawStart = -lineHeight / 2 + env->r.height / 2;
// 		if(drawStart < 0)drawStart = 0;
// 		int drawEnd = lineHeight / 2 + env->r.height / 2;
// 		if(drawEnd >= env->r.height)drawEnd = env->r.height - 1;

// 		//choose wall color
// 		int color;
// 		switch(env->map_array.lines[mapY]->line[mapX])
// 		{
// 			case 1:  color = MASK_R;  break; //red
// 			case 2:  color = MASK_G;  break; //green
// 			default:  color = MASK_B;   break; //blue
// 		}

// 		//give x and y sides different brightness
// 		if (side == 1) {color = color / 2;}

// 		//draw the pixels of the stripe as a vertical line
// 		// verLine(x, drawStart, drawEnd, color);
// 		draw_rect(datas, (t_coordinates){current_x, drawStart}, (t_coordinates){current_x, drawEnd}, color);

// 		current_x ++;
// 	}


// }

// void	print_img(t_env *env)
// {
// 	int i;

// 	i = 0;
// 	if (env->imgs[i].img != NULL)
// 		mlx_destroy_image(env->mlx, env->imgs[i].img);

//     env->imgs[i].img = mlx_new_image(env->mlx, env->r.width, env->r.height);
//     env->imgs[i].addr = mlx_get_data_addr(env->imgs[i].img,	&env->imgs[i].bits_per_pixel, &env->imgs[i].line_length, &env->imgs[i].endian);

// 	draw_ceiling_floor(&env->imgs[i], env);
// 	draw_walls(&env->imgs[i], env);

//     mlx_put_image_to_window(env->mlx, env->win, env->imgs[i].img, 0, 0);

// }

// // int             key_press(int keycode, t_env *env)
// // {
// //     printf("Hello from key_press! %c\n", keycode); //single event ? 
// // }

// int             key_release(int keycode, t_env *env)
// {
// 	int i;

// 	i = -1;
// 	while (i++ < MAX_ACTIONS - 1)
// 		if (keycode == env->actions[i].keycode)
// 		{
// 			env->actions[i].is_asked = 0;
// 			break ;
// 		}
// 	return keycode;
// }

// int             key_press(int keycode, t_env *env)
// {
// 	int i;

// 	i = -1;
// 	while (i++ < MAX_ACTIONS - 1)
// 		if (keycode == env->actions[i].keycode)
// 		{
// 			env->actions[i].is_asked = 1;
// 			break ;
// 		}
// 	return keycode;
// }

// int		quit_cub3d(t_env *env)
// {
// 	printf("QUITTING ! \n");
// 	// mlx_destroy_image(env->mlx, game->screen.ptr);
// 	mlx_destroy_window(env->mlx, env->win);
// 	// free_env(env);
// }

// int		close_window(t_env *env)
// {
// 	env->actions[ESCAPE_ID].is_asked = 1;
// 	return (0);
// }

// int		game_loop(t_env *env)
// {
// 	if(env->win){
// 		print_img(env);
// 		// img.img = mlx_new_image(env->mlx, env->r.width, env->r.height);
// 		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//         //                          &img.endian);
// 		// my_mlx_pixel_put(&img, env->r.width-1, env->r.height-1, MASK_B); //de 0 a width -1 ou a height -1
// 		// mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
// 	}

// 	int i;

// 	i = -1;
// 	while (i++ < MAX_ACTIONS)
// 	{
// 		if (env->actions[i].is_asked == 1)
// 		{
// 			env->actions[i].fun(env);
// 		}
// 	}
// 	return (0);
// }

// int rotate_left(t_env *env)
// {
// 	rotation(&env->direction, -(env->fov_angle / ROTATE_DIV));
// 	return (EXIT_SUCCESS);
// }

// int rotate_rigth(t_env *env)
// {
// 	rotation(&env->direction, (env->fov_angle / ROTATE_DIV));
// 	return (EXIT_SUCCESS);
// }

// int run_up(t_env *env)
// {
// 	env->try_to_run_dir.y-= QUOTIENT_MOVE;
// 	env->actions[ACTUALLY_RUN].is_asked = 1;
// 	return (EXIT_SUCCESS);
// }

// int run_down(t_env *env)
// {
// 	env->try_to_run_dir.y+= QUOTIENT_MOVE;
// 	env->actions[ACTUALLY_RUN].is_asked = 1;
// 	return (EXIT_SUCCESS);
// }

// int run_right(t_env *env)
// {
// 	env->try_to_run_dir.x+= QUOTIENT_MOVE;
// 	env->actions[ACTUALLY_RUN].is_asked = 1;
// 	return (EXIT_SUCCESS);
// }

// int run_left(t_env *env)
// {
// 	env->try_to_run_dir.x-= QUOTIENT_MOVE;
// 	env->actions[ACTUALLY_RUN].is_asked = 1;
// 	return (EXIT_SUCCESS);
// }

// t_coordinates calc_run_dir(t_env *env)
// {
// 	t_coordinates	run_dir;
// 	float			pi_quotient;

// 	pi_quotient = ((env->try_to_run_dir.x != 0 ? -(env->try_to_run_dir.x - 1): 
// 	0) + (env->try_to_run_dir.y != 0 ? (-env->try_to_run_dir.y + 2): 0));
// 	if(env->try_to_run_dir.x == +1 && env->try_to_run_dir.y == -1)
// 		pi_quotient = 7;
// 	run_dir.x = env->direction.x;
// 	run_dir.y = env->direction.y;
// 	rotation(&run_dir, (pi_quotient * M_PI) / (float) ((env->try_to_run_dir.y
// 	 != 0 && env->try_to_run_dir.x != 0) ? 4: 2));

// 	return (run_dir);
// }

// int actually_run(t_env *env)
// {
// 	// printf("RUNNING %f:%f\n", env->current_pos.x, env->current_pos.y);
// 	// printf("DURECTION %f:%f\n", env->direction.x, env->direction.y);
// // 	printf("try_to_run_dir %f:%f\n", env->try_to_run_dir.x, env->try_to_run_dir.y);

// 	env->actions[ACTUALLY_RUN].is_asked = 0;

// 	t_coordinates run_dir = calc_run_dir(env);
// 	t_coordinates new_pos = (t_coordinates){env->current_pos.x + run_dir.x * RUN_STEP, env->current_pos.y + run_dir.y * RUN_STEP};

// 	if(env->map_array.lines[(int)(new_pos.y + (env->try_to_run_dir.y * WALL_HIT_BOX))]->line[(int)(env->current_pos.x)] != '1') // (new_pos.x + (env->try_to_run_dir.x * WALL_HIT_BOX)))
// 	// {
// 		// printf("%c\n", env->map_array.lines[(int)(new_pos.y + (env->try_to_run_dir.y * WALL_HIT_BOX))]->line[(int)(env->current_pos.x)]);
// 		env->current_pos.y = new_pos.y;
// 	// }
// 	if(env->map_array.lines[(int)(env->current_pos.y)]->line[(int)(new_pos.x + (env->try_to_run_dir.x * WALL_HIT_BOX))] != '1') // 
// 		env->current_pos.x = new_pos.x;
// 	// printf("RUNNING NEW POS %f:%f\n", new_pos.x, new_pos.y);
// 	env->try_to_run_dir = (t_coordinates){0, 0};
// 	return (EXIT_SUCCESS);
// }

// void	init_actions(t_env *env)
// {
// 	env->actions[ESCAPE_ID] = (t_action){0, XK_Escape, &quit_cub3d};
// 	env->actions[ROTATE_LEFT_ID] = (t_action){0, XK_Left, &rotate_left};
// 	env->actions[ROTATE_RIGHT_ID] = (t_action){0, XK_Right, &rotate_rigth};
// 	env->actions[GO_LEFT_A_ID] = (t_action){0, XK_a, &run_left};
// 	env->actions[GO_RIGTH_D_ID] = (t_action){0, XK_d, &run_right};
// 	env->actions[GO_BACK_S_ID] = (t_action){0, XK_s, &run_down};
// 	env->actions[GO_FRONT_W_ID] = (t_action){0, XK_w, &run_up};
// 	env->actions[ACTUALLY_RUN] = (t_action){0, -1, &actually_run};
// }

// void	init_imgs(t_env *env)
// {
// 	int i;

// 	i = -1;
// 	while (i++ < MAX_IMGS - 1)
// 		env->imgs[i] = (t_data){NULL, NULL, -1, -1, -1};
// }

// void	correct_max_dimension(t_env *env)
// {
// 	int sizex;
// 	int sizey;

// 	sizex = 0;
// 	sizey = 0;
// 	mlx_get_screen_size(env->mlx, &sizex, &sizey);
// 	if(sizex < env->r.width)
// 		env->r.width = sizex;
// 	if(sizey < env->r.height)
// 		env->r.height = sizey;
// }

// void	init_fov(t_env *env)
// {
// 	env->fov_angle = FOV * M_PI / (MAX_DEGREES / 2);
// }

// int	init_textures(t_env *env)
// {
// 	int i;

// 	i = 0;
// 	while (i < MAX_TEX)
// 	{
// 		env->textures[i].img = mlx_xpm_file_to_image(env->mlx,
// 		env->g_srcs[i].src, &env->textures[i].w, &env->textures[i].h);
// 		if(!env->textures[i].img)
// 			return (-EXIT_FAILURE);
// 		env->textures[i].addr = mlx_get_data_addr(env->textures[i].img,
// 		&env->textures[i].bits_per_pixel, &env->textures[i].line_length,
// 		&env->textures[i].endian);
// 		if(!env->textures[i].img)
// 			return (-EXIT_FAILURE);
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

// void	plane_calc(t_cartesian_vector dir, t_cartesian_vector *plane, float angle)
// {
// 	plane->dir.x = dir.dir.x;
// 	plane->dir.y = dir.dir.y;
// 	rotation(plane, angle);
// 	plane->dir.x *= tan(angle / 2);
// 	plane->dir.y *= tan(angle / 2);
// }


void	start_cub_3d(t_env *env)
{
	// init_actions(env);
	// init_imgs(env);
	// init_fov(env);
	// env->count = 0;
    // env->mlx = mlx_init();
	// correct_max_dimension(env);
	// if (init_textures(env) != EXIT_SUCCESS){
	// 	printf("Error encountered while initializing textures, the files may not exist\n");
	// 	free_env(env);
	// 	exit(-EXIT_FAILURE);
	// }
	// t_cartesian_vector dir = {};
	// t_cartesian_vector plane = {};
	// plane_calc(dir, &plane, 90);
	// printf("PLANE %f:%f\n", plane.dir.x, plane.dir.y);
	// printf("PLANE %f\n",  2 * atan(0.66/1.0));

    // env->win = mlx_new_window(env->mlx, env->r.width, env->r.height, "Cub3D");

	// print_img(env);

	// // mlx_hook(env->win, DestroyNotify, StructureNotifyMask, key_hook, (void *)0);

	// mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	// mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	// mlx_hook(env->win, DestroyNotify, StructureNotifyMask, close_window, env);
	// mlx_loop_hook(env->mlx, game_loop, env);
    // mlx_loop(env->mlx);

	// free_env(env);
}
