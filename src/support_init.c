/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:01:43 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 15:01:46 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that init the elements to output
** the playing window, also used to init the textures
** and menu in the game
*/

t_graphic			*ft_init_graph(void)
{
	t_graphic		*graph;

	if (!(graph = (t_graphic *)malloc(sizeof(t_graphic))))
		return (NULL);
	graph->mlx_ptr = NULL;
	graph->win_ptr = NULL;
	graph->img_ptr = NULL;
	graph->height = W_H;
	graph->width = W_W;
	graph->img = NULL;
	return (graph);
}

/*
** function that init all the element needed to
** run the raycasting
*/

t_raycast			*ft_init_ray(void)
{
	t_raycast		*ray;

	if (!(ray = (t_raycast*)malloc(sizeof(t_raycast))))
		return (NULL);
	ray->fov = 0.66;
	ray->gridx = 0.0;
	ray->gridy = 0.0;
	ray->camx = 0.0;
	ray->camy = ray->fov;
	ray->rayx = 0.0;
	ray->rayy = 0.0;
	ray->move_speed = 0.1;
	ray->angle_rotate = 0.10;
	ray->length = 0.0;
	ray->ratio = 0.0;
	ray->vstepx = 0.0;
	ray->vstepy = 0.0;
	ray->xdir = -1.0;
	ray->ydir = 0.0;
	ray->px = 0.0;
	ray->py = 0.0;
	ray->xstep = 0.0;
	return (ray);
}

/*
** function that init the texture for the game
*/

void				ft_init_texture(t_data *env)
{
	if ((env->wall1->img_ptr = mlx_xpm_file_to_image(env->graph->mlx_ptr,
					"texture/wall1.xpm",
					&env->wall1->width, &env->wall1->height)) != NULL)
		env->wall1->img = mlx_get_data_addr(env->wall1->img_ptr,
				&(env->wall1->bpp),
				&(env->wall1->s_l), &(env->wall1->endian));
	if ((env->wall2->img_ptr = mlx_xpm_file_to_image(env->graph->mlx_ptr,
					"texture/wall2.xpm",
					&env->wall2->width, &env->wall2->height)) != NULL)
		env->wall2->img = mlx_get_data_addr(env->wall2->img_ptr,
				&(env->wall2->bpp),
				&(env->wall2->s_l), &(env->wall2->endian));
	if ((env->wall3->img_ptr = mlx_xpm_file_to_image(env->graph->mlx_ptr,
					"texture/wall3.xpm",
					&env->wall3->width, &env->wall3->height)) != NULL)
		env->wall3->img = mlx_get_data_addr(env->wall3->img_ptr,
				&(env->wall3->bpp),
				&(env->wall3->s_l), &(env->wall3->endian));
	if ((env->wall4->img_ptr = mlx_xpm_file_to_image(env->graph->mlx_ptr,
					"texture/wall4.xpm",
					&env->wall4->width, &env->wall4->height)) != NULL)
		env->wall4->img = mlx_get_data_addr(env->wall4->img_ptr,
				&(env->wall4->bpp),
				&(env->wall4->s_l), &(env->wall4->endian));
}
