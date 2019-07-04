/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:34:42 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 13:49:17 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that cleans the window
*/

static int				ft_destroy_key(t_data *env)
{
	mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
	mlx_destroy_window(env->graph->mlx_ptr, env->graph->win_ptr);
	free_struct(env);
	exit(EXIT_SUCCESS);
}

/*
** function that increase or decrease the speed of the player
*/

static int				ft_speed(t_data *env, int key)
{
	static int m = 0;

	if (key == LEFT_SHIFT)
		if (m == 0)
		{
			env->ray->move_speed = env->ray->move_speed + 0.45;
			m++;
		}
	if (key == RIGHT_SHIFT)
		if (m == 1)
		{
			env->ray->move_speed = env->ray->move_speed - 0.45;
			m = 0;
		}
	return (0);
}

/*
** function that prints the options on screen
** during the game
*/

void					ft_option(int key, t_data *env)
{
	if (key == O)
	{
		mlx_string_put(env->graph->mlx_ptr, env->graph->win_ptr, 10, 15,
			0Xede923, "ESC to QUIT");
		mlx_string_put(env->graph->mlx_ptr, env->graph->win_ptr, 10, 35,
			0Xede923, "M for MAP");
		mlx_string_put(env->graph->mlx_ptr, env->graph->win_ptr, 10, 55,
			0Xede923, "left SHIFT for + SPEED");
		mlx_string_put(env->graph->mlx_ptr, env->graph->win_ptr, 10, 75,
			0Xede923, "right SHIFT for - SPEED");
	}
}

/*
** function that takes care of the key event
*/

int						deal_key(int key, t_data *env)
{
	static int j = 0;

	if (key == ENTER)
	{
		env->menu++;
		new_image(env);
	}
	if (key == ESC)
		ft_destroy_key(env);
	if (key == DOWN_ARROW || key == UP_ARROW
		|| key == LEFT_ARROW || key == RIGHT_ARROW
		|| key == A || key == D)
	{
		ft_perso_move(key, env);
		j = 0;
	}
	ft_speed(env, key);
	j = ft_map(env, key, j);
	ft_option(key, env);
	return (0);
}
