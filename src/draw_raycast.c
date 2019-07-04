/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:45:46 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 11:23:41 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that calculates the length of the sky, wall and ground
*/

void			ray_draw(t_data *env, int x)
{
	int			wall_height;
	int			sky;
	int			ground;

	wall_height = (int)(env->height / env->ray->length);
	sky = -wall_height * 0.5 + env->height * 0.5;
	if (sky < 0)
		sky = 0;
	ground = wall_height * 0.5 + env->height * 0.5;
	if (ground >= env->height)
		ground = env->height - 1;
	ft_draw_line(env, x, sky, ground);
}

/*
** function that draw the sky, gound and wall
*/

void			ft_draw_line(t_data *env, int x, int sky, int ground)
{
	int				i;
	int				wall_height;
	int				color;

	wall_height = 0;
	i = -1;
	wall_height = (int)(env->height / env->ray->length);
	while (++i < sky)
	{
		img_pixel(env, x, i, env->color_sky);
	}
	i--;
	while (++i <= ground)
	{
		ft_which_face(env);
		color = ft_wall(env, i, wall_height);
		img_pixel(env, x, i, color);
	}
	i--;
	while (++i < env->height)
		img_pixel(env, x, i, env->color_ground);
}

/*
** function that draw the wall part of the raycast with the texture
*/

int				ft_wall(t_data *env, int i, int wall_height)
{
	int			tx;
	int			ty;
	int			color;
	double		hit_horz;

	hit_horz = ft_hit_coord(env);
	color = 0;
	ty = 0;
	tx = 0;
	tx = (int)(hit_horz * (double)env->text_width) % env->text_width;
	ty = ((i - (env->height * 0.5) + (wall_height * 0.5))
		* env->text_height) / wall_height;
	if (ty < env->text_height)
		color = ((int*)env->text_img)[(ty * env->text_width + tx)];
	return (color);
}

/*
** function that finds the precise hit of the ray on the x coordinate
*/

double			ft_hit_coord(t_data *env)
{
	double		hit_horz;

	if (env->rayhitside == 0)
		hit_horz = env->ray->py + env->ray->length * env->ray->rayy;
	else
		hit_horz = env->ray->px + env->ray->length * env->ray->rayx;
	hit_horz -= floor((hit_horz));
	return (hit_horz);
}
