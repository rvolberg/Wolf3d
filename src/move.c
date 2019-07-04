/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:47:15 by tlaberro          #+#    #+#             */
/*   Updated: 2019/03/22 12:09:42 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that redirect to the correct function when the
** player moves
*/

int			ft_perso_move(int key, t_data *env)
{
	if (key == LEFT_ARROW)
		ft_move_right_left(env, key);
	if (key == RIGHT_ARROW)
		ft_move_right_left(env, key);
	if (key == DOWN_ARROW)
		ft_move_up_down(env, key);
	if (key == UP_ARROW)
		ft_move_up_down(env, key);
	if (key == A)
		rotate_left(env);
	if (key == D)
		rotate_right(env);
	return (0);
}

void		ft_move_up_down(t_data *env, int key)
{
	double	xtmp;
	double	ytmp;

	xtmp = env->ray->xdir * env->ray->move_speed;
	ytmp = env->ray->ydir * env->ray->move_speed;
	mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
	if (key == UP_ARROW)
	{
		if (env->tab_int[(int)(env->ray->px + xtmp)][(int)env->ray->py].z == 0)
			env->ray->px += xtmp;
		if (env->tab_int[(int)env->ray->px][(int)(env->ray->py + ytmp)].z == 0)
			env->ray->py += ytmp;
	}
	else
	{
		if (env->tab_int[(int)(env->ray->px - xtmp)][(int)env->ray->py].z == 0)
			env->ray->px -= xtmp;
		if (env->tab_int[(int)env->ray->px][(int)(env->ray->py - ytmp)].z == 0)
			env->ray->py -= ytmp;
	}
	new_image(env);
}

void		ft_move_right_left(t_data *env, int key)
{
	double	xtmp;
	double	ytmp;

	xtmp = env->ray->camx * env->ray->move_speed;
	ytmp = env->ray->camy * env->ray->move_speed;
	mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
	if (key == RIGHT_ARROW)
	{
		if (env->tab_int[(int)(env->ray->px + xtmp)][(int)env->ray->py].z == 0)
			env->ray->px += xtmp;
		if (env->tab_int[(int)env->ray->px][(int)(env->ray->py + ytmp)].z == 0)
			env->ray->py += ytmp;
	}
	else
	{
		if (env->tab_int[(int)(env->ray->px - xtmp)][(int)env->ray->py].z == 0)
			env->ray->px -= xtmp;
		if (env->tab_int[(int)env->ray->px][(int)(env->ray->py - ytmp)].z == 0)
			env->ray->py -= ytmp;
	}
	new_image(env);
}

void		rotate_right(t_data *data)
{
	double	ptr;

	mlx_clear_window(data->graph->mlx_ptr, data->graph->win_ptr);
	ptr = data->ray->xdir;
	data->ray->xdir = data->ray->xdir * cos(-data->ray->angle_rotate)
		- data->ray->ydir * sin(-data->ray->angle_rotate);
	data->ray->ydir = ptr * sin(-data->ray->angle_rotate) + data->ray->ydir
		* cos(-data->ray->angle_rotate);
	ptr = data->ray->camx;
	data->ray->camx = data->ray->camx
		* cos(-data->ray->angle_rotate) - data->ray->camy
		* sin(-data->ray->angle_rotate);
	data->ray->camy = ptr * sin(-data->ray->angle_rotate) + data->ray->camy
		* cos(-data->ray->angle_rotate);
	new_image(data);
}

void		rotate_left(t_data *data)
{
	double	ptr;

	mlx_clear_window(data->graph->mlx_ptr, data->graph->win_ptr);
	ptr = data->ray->xdir;
	data->ray->xdir = data->ray->xdir * cos(data->ray->angle_rotate)
		- data->ray->ydir * sin(data->ray->angle_rotate);
	data->ray->ydir = ptr * sin(data->ray->angle_rotate) + data->ray->ydir
		* cos(data->ray->angle_rotate);
	ptr = data->ray->camx;
	data->ray->camx = data->ray->camx
		* cos(data->ray->angle_rotate) - data->ray->camy
		* sin(data->ray->angle_rotate);
	data->ray->camy = ptr * sin(data->ray->angle_rotate) + data->ray->camy
		* cos(data->ray->angle_rotate);
	new_image(data);
}
