/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:42:34 by tlaberro          #+#    #+#             */
/*   Updated: 2019/03/22 13:48:41 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

static void		comp(char *str)
{
	char *path;

	path = "/dev/zero";
	if (ft_strncmp(str, path, 8) == 0)
	{
		ft_putendl("/dev/zero unvailable");
		exit(EXIT_FAILURE);
	}
}

static void		ft_check_window(t_data *env)
{
	if (env->height != 800 || env->width != 1280 ||
		env->graph->height != 800 || env->graph->width != 1280)
	{
		env->height = 800;
		env->graph->height = 800;
		env->width = 1280;
		env->graph->width = 1280;
	}
}

/*
** main function
*/

int				main(int ac, char **av)
{
	t_data	*env;

	env = NULL;
	if (ac == 2)
	{
		comp(av[1]);
		if (!(env = ft_init_struct(env)))
		{
			free_struct(env);
			ft_putendl_fd("malloc():\tFAILLED", 2);
			return (EXIT_FAILURE);
		}
		ft_reader(env, av[1]);
		ft_init_list(env);
		if ((env->graph->mlx_ptr = mlx_init()) == NULL)
		{
			free_struct(env);
			ft_putendl_fd("Error:\tconnection to graphical server failed", 2);
			return (EXIT_FAILURE);
		}
		ft_check_window(env);
		ft_place_perso(env);
		ft_init_window(env);
		ft_window_output(env);
	}
	else
		ft_putendl_fd("./wolf3d\t[map]", 2);
	return (0);
}
