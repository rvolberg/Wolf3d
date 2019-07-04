/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:12:40 by tlaberro          #+#    #+#             */
/*   Updated: 2019/02/26 18:29:35 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that draws a square in the mini map at the given
** coodinate
*/

void			ft_print_square(t_data *env, int x, int y, int color)
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;

	x1 = x;
	y1 = y;
	x2 = (env->cube + x);
	y2 = (env->cube + y);
	while (y1 < y2)
	{
		while (x1 < x2)
		{
			img_pixel(env, x1, y1, color);
			x1++;
		}
		x1 = x;
		y1++;
	}
}

/*
** function that draws the player in the mini map at the given
** coordinate
*/

void			ft_print_perso(t_data *env, int x, int y, int color)
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;

	x1 = x;
	y1 = y;
	x2 = (env->cube / 2) + x;
	y2 = (env->cube / 2) + y;
	while (y1 < y2)
	{
		while (x1 < x2)
		{
			img_pixel(env, x1, y1, color);
			x1++;
		}
		x1 = x;
		y1++;
	}
}

/*
** function that draw the minimap
*/

void			ft_draw_mini(t_data *env)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < env->line)
	{
		while (x < env->column)
		{
			if (env->tab_int[y][x].z == 1)
			{
				ft_print_square(env, env->tab_int[y][x].x,
								env->tab_int[y][x].y, 0x808080);
			}
			if (env->tab_int[y][x].z == 0)
			{
				ft_print_square(env, env->tab_int[y][x].x,
								env->tab_int[y][x].y, 0xFFFFFF);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

/*
** function that draws the mini map when SHIFT key is used
*/

int				ft_map(t_data *env, int key, int j)
{
	if (key == 46 && env->menu != 0)
	{
		mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
		if (j == 0 || j == 2)
		{
			ft_draw_mini(env);
			ft_print_perso(env,
					env->tab_int[(int)env->ray->px]
					[(int)env->ray->py].x
					+ (CUBE_SIZE / 4),
					env->tab_int[(int)env->ray->px]
					[(int)env->ray->py].y
					+ (CUBE_SIZE / 4), 0x000000);
		}
		if (j == 1)
			new_image(env);
		if (j == 2)
			j = 0;
		j++;
		mlx_put_image_to_window(env, env->graph->win_ptr,
								env->graph->img_ptr, 0, 0);
	}
	return (j);
}
