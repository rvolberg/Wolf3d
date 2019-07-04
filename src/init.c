/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:34:20 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 11:27:24 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that init the rest of the data struct
*/

static void			support_initstruct(t_data *env)
{
	env->color_1 = 0xF4F142;
	env->color_2 = 0x50F442;
	env->color_3 = 0x42E8F4;
	env->color_4 = 0xEE42F4;
	env->color_sky = 0x5A5657;
	env->color_ground = 0x383334;
	env->menu = 0;
	env->width = W_W;
	env->height = W_H;
	env->xi = 0;
	env->yi = 0;
	env->map = NULL;
	env->ray->ystep = 0.0;
}

static t_data				*support_init(t_data *env)
{
	if (!(env->ray = ft_init_ray()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env->wall1 = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env->wall2 = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env->wall3 = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	return (env);
}

static t_data				*support_init_bis(t_data *env)
{
	if (!(env->graph = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env->wall4 = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env->menu1 = ft_init_graph()))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	return (env);
}

/*
** function that init the super struct
*/

t_data				*ft_init_struct(t_data *env)
{
	if (!(env = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!(env = support_init(env)))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	if (!(env = support_init_bis(env)))
	{
		free_struct(env);
		ft_putendl_fd("malloc():\tFAILLED", 2);
		return (NULL);
	}
	env->tab_int = NULL;
	env->map_raw = NULL;
	env->fd = 0;
	env->column = 0;
	env->line = 0;
	env->xdecale = 0;
	env->ydecale = 0;
	env->cube = CUBE_SIZE;
	support_initstruct(env);
	return (env);
}
