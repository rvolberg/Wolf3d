/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_draw_raycast.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:24:56 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/12 13:38:07 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that find on which wall we are
*/

unsigned int	get_color(t_data *env)
{
	if (env->rayhitside == 1)
	{
		if ((env->ray->xstep == -1 && env->ray->ystep == -1)
				|| (env->ray->xstep == 1 && env->ray->ystep == -1))
			return (env->color_1);
		if ((env->ray->xstep == -1 && env->ray->ystep == 1)
				|| (env->ray->xstep == 1 && env->ray->ystep == 1))
			return (env->color_2);
	}
	if ((env->ray->xstep == -1 && env->ray->ystep == -1)
			|| (env->ray->xstep == -1 && env->ray->ystep == 1))
		return (env->color_3);
	return (env->color_4);
}

/*
** function that support the ft_which_face function
*/

void			support_wall(t_data *env, int h, int w, char *img)
{
	env->text_height = h;
	env->text_width = w;
	env->text_img = img;
}

/*
** function that gives the texture according to the wall
** we are on
*/

void			ft_which_face(t_data *env)
{
	int face;

	face = get_color(env);
	if (face == env->color_1)
		support_wall(env, env->wall1->height, env->wall1->width,
			env->wall1->img);
	if (face == env->color_2)
		support_wall(env, env->wall2->height, env->wall2->width,
			env->wall2->img);
	if (face == env->color_3)
		support_wall(env, env->wall3->height, env->wall3->width,
			env->wall3->img);
	if (face == env->color_4)
		support_wall(env, env->wall4->height, env->wall4->width,
			env->wall4->img);
}
