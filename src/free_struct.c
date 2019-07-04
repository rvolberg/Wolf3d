/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:32:09 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 13:47:34 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void		free_texture(t_data *env)
{
	if (env->wall1 != NULL)
		free(env->wall1);
	if (env->wall2 != NULL)
		free(env->wall2);
	if (env->wall3 != NULL)
		free(env->wall3);
	if (env->wall4 != NULL)
		free(env->wall4);
	if (env->menu1 != NULL)
		free(env->menu1);
}

void			free_struct(t_data *env)
{
	int			i;

	i = 0;
	if (env != NULL)
	{
		if (env->graph != NULL)
			free(env->graph);
		free_texture(env);
		if (env->tab_int != NULL)
		{
			while (i < env->line)
			{
				free(env->tab_int[i]);
				i++;
			}
			free(env->tab_int);
		}
		if (env->map_raw != NULL)
			free(env->map_raw);
		if (env->ray != NULL)
			free(env->ray);
		if (env->map != NULL)
			ft_free_tab_data(env->map, env->line);
		free(env);
	}
}
