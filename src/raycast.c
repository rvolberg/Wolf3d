/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:25:08 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 11:45:49 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** main part of the raycasting
** we work with a ratio for the screen (going form -1, left to 1, right)
*/

void			raycasting(t_data *env)
{
	int			x;
	static int	first_offset = 0;

	x = -1;
	if (first_offset == 0)
	{
		env->ray->py = env->xi + 0.5;
		env->ray->px = env->yi + 0.5;
		first_offset++;
	}
	while (++x < env->width)
	{
		env->ray->gridx = (int)env->ray->px;
		env->ray->gridy = (int)env->ray->py;
		env->ray->ratio = 2 * x / (double)env->width - 1;
		ft_supportray(env);
		env->rayhit = 0;
		env->ray->length = -1;
		env->rayhitside = -1;
		ray_first_step_side(env);
		ray_cal_dist(env);
		ray_draw(env, x);
	}
}

/*
** function that support the raycasting
** vstepx vstepy are "ratio" variable use to
** calculate the irregular sidestepx sidestepy
*/

void			ft_supportray(t_data *env)
{
	env->ray->rayx = env->ray->xdir + (env->ray->camx * env->ray->ratio);
	env->ray->rayy = env->ray->ydir + (env->ray->camy * env->ray->ratio);
	env->ray->vstepx = sqrt(1 + pow(env->ray->rayy, 2)
			/ pow(env->ray->rayx, 2));
	env->ray->vstepy = sqrt(1 + pow(env->ray->rayx, 2)
			/ pow(env->ray->rayy, 2));
}

/*
** function that depending on the side of the cam plane we are going
** (left of right) calculate the size of the steps horizontal
** and vertical
*/

void			ray_first_step_side(t_data *env)
{
	if (env->ray->rayx < 0)
	{
		env->ray->xstep = -1;
		env->sidedistx = (env->ray->px - env->ray->gridx)
			* env->ray->vstepx;
	}
	else
	{
		env->ray->xstep = 1;
		env->sidedistx = (env->ray->gridx + 1 - env->ray->px)
			* env->ray->vstepx;
	}
	if (env->ray->rayy < 0)
	{
		env->ray->ystep = -1;
		env->sidedisty = (env->ray->py - env->ray->gridy)
			* env->ray->vstepy;
	}
	else
	{
		env->ray->ystep = 1;
		env->sidedisty = (env->ray->gridy + 1 - env->ray->py)
			* env->ray->vstepy;
	}
}

/*
** using DDA (digital differential analyzer) we jump in the vertical
** or horizontal direction and calculate the projected lenght to the
** plane of the camera
*/

void			ray_cal_dist(t_data *env)
{
	while (env->rayhit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->ray->vstepx;
			env->ray->gridx += env->ray->xstep;
			env->rayhitside = 0;
		}
		else
		{
			env->sidedisty += env->ray->vstepy;
			env->ray->gridy += env->ray->ystep;
			env->rayhitside = 1;
		}
		if (env->tab_int[(int)env->ray->gridx][(int)env->ray->gridy].z > 0)
		{
			env->rayhit = 1;
			if (env->rayhitside == 0)
				env->ray->length = (env->ray->gridx - env->ray->px
					+ (1 - env->ray->xstep) * 0.5) / env->ray->rayx;
			else
				env->ray->length = (env->ray->gridy - env->ray->py
					+ (1 - env->ray->ystep) * 0.5) / env->ray->rayy;
		}
	}
}
