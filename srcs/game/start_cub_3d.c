/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:54:29 by scarboni          #+#    #+#             */
/*   Updated: 2021/09/24 14:59:36 by scarboni         ###   ########.fr       */
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

int             key_press(int keycode, t_env *env)
{
	int i;

	i = -1;
	while (i++ < MAX_ACTIONS)
		if (keycode == g_actions[i].keycode)
		{
			g_actions[i].fun(env);
			break ;
		}
	return keycode;
}

int		close_window(t_env *env)
{
	env->quitting = true;
	return (0);
}

int		game_loop(t_env *env)
{
	if(env->win){
		print_img(env);
		// img.img = mlx_new_image(env->mlx, env->r.width, env->r.height);
		// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        //                          &img.endian);
		// my_mlx_pixel_put(&img, env->r.width-1, env->r.height-1, MASK_B); //de 0 a width -1 ou a height -1
		// mlx_put_image_to_window(env->mlx, env->win, img.img, 0, 0);
	}

	// int i;

	// i = -1;
	// while (i++ < MAX_ACTIONS)
	// {
	// 	if (g_actions[i].is_asked == 1)
	// 	{
	// 		env->actions[i].fun(env);
	// 	}
	// }
	if(env->quitting == true)
		g_actions[XK_Escape].fun(env);
	return (0);
}

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


void	init_imgs(t_env *env)
{
	int i;

	i = -1;
	while (i++ < MAX_IMGS - 1)
		env->imgs[i] = (t_data){NULL, NULL, -1, -1, -1, -1, -1};
}

int	correct_max_dimension(t_env *env)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(env->mlx, &sizex, &sizey);
	if(sizex < (env->map_array.width * TILE_SIZE))
		return (-EXIT_FAILURE);
	if(sizey < (env->map_array.height * TILE_SIZE))
		return (-EXIT_FAILURE);
	env->win_max_dimensions.x = env->map_array.width * TILE_SIZE;
	env->win_max_dimensions.y = env->map_array.height * TILE_SIZE;
	return (EXIT_SUCCESS);
}

int	init_texture(t_env *env, char* src, t_data* tex)
{
	tex->img = mlx_xpm_file_to_image(env->mlx,
	src, &tex->w, &tex->h);
	if (!tex->img)
		return (-EXIT_FAILURE);
	tex->addr = mlx_get_data_addr(tex->img,
	&tex->bits_per_pixel, &tex->line_length,
	&tex->endian);
	if(!tex->addr)
		return (-EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_textures(t_env *env)
{
	int i;

	i = 0;
	while (i < MAX_BLOCKS_PROPERTIES)
	{
		if (init_texture(env, env->blocks_properties[i].src, &env->blocks_properties[i].tex) < EXIT_SUCCESS)
			return (-EXIT_FAILURE);
		i++;
	}
	if (init_texture(env, env->main.src, &env->main.tex) < EXIT_SUCCESS)
		return (-EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_blocks_properties(t_env *env)
{
	int i;

	i = 0;
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_EXIT, EXIT_SRC, NULL, NULL, (t_data){}};
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_WALL, WALL_SRC, NULL, NULL, (t_data){}};
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_COLLECTIBLE, COLLECTIBLE_SRC, NULL, NULL, (t_data){}};
	#ifdef BONUS
	env->blocks_properties[i++] = (t_block_properties){AUTHORIZED_ON_MAP_PATROL, PATROL_SRC, NULL, NULL, (t_data){}};
	# endif
	env->main = (t_main_character){MAIN_SRC, NULL, 0, (t_data){}};
	return (init_textures(env));
}

void	start_cub_3d(t_env *env)
{
	init_imgs(env);
	env->count = 0;
    env->mlx = mlx_init();
	if (correct_max_dimension(env) < EXIT_SUCCESS)
		quit_app(env, "The map is too big for the screen", -EXIT_FAILURE);
	if (init_blocks_properties(env) < EXIT_SUCCESS)
		quit_app(env, "Error encountered while initializing textures, the files may not exist", -EXIT_FAILURE);
	

    env->win = mlx_new_window(env->mlx, env->win_max_dimensions.x, env->win_max_dimensions.y, "So long !");

	print_img(env);

	// // mlx_hook(env->win, DestroyNotify, StructureNotifyMask, key_hook, (void *)0);

	mlx_hook(env->win, KeyPress, KeyPressMask, key_press, env);
	// mlx_hook(env->win, KeyRelease, KeyReleaseMask, key_release, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask, close_window, env);
	mlx_loop_hook(env->mlx, game_loop, env);
    mlx_loop(env->mlx);

	// free_env(env);
}
