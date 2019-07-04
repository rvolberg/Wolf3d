/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:39:07 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 13:14:47 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that read the map from the given file
** and stock it
*/

void			ft_reader(t_data *env, char *av)
{
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	env->fd = ft_open(av, env);
	if (!(env->map_raw = ft_memalloc(1)))
	{
		env->map_raw = NULL;
		ft_exit(env->fd, env, "malloc():\tFAILLED");
	}
	while ((i = get_next_line(env->fd, &line)) > 0)
	{
		ft_charcheck(line, env->fd, env);
		ft_placecheck(line, env->fd, env);
		env->map_raw = ft_strjoin_free(env->map_raw, line);
		ft_strdel(&line);
		env->map_raw = ft_back_n(env->map_raw, env->fd, env);
	}
	if (i == -1)
		ft_exit(env->fd, env, "Error 0:\tinvalid map");
	ft_read_support(env, line);
}

/*
** support function of ft_reader
*/

void			ft_read_support(t_data *env, char *line)
{
	if (env->map_raw[0] == '\0')
		ft_exit(env->fd, env, "Error 0:\tinvalid map");
	if (!(env->map = ft_strsplit(env->map_raw, '\n')))
	{
		env->map = NULL;
		ft_exit(env->fd, env, "malloc():\tFAILLED");
	}
	ft_checkwall(env->map, env);
	ft_strdel(&line);
	ft_strdel(&env->map_raw);
	close(env->fd);
}

/*
** function that initialize the two dimentional
** tab that contain the given map
*/

int				ft_init_list(t_data *env)
{
	int			i;

	i = 0;
	if (!(env->tab_int = (t_pixel **)malloc(sizeof(t_pixel *)
					* (env->line + 2))))
	{
		env->tab_int = NULL;
		ft_putendl("error open");
		free_struct(env);
		exit(EXIT_FAILURE);
	}
	while (i < env->line)
	{
		if (!(env->tab_int[i] = (t_pixel*)malloc(sizeof(t_pixel)
			* env->column)))
		{
			env->tab_int[i] = NULL;
			ft_exit(env->fd, env, "malloc():\tFAILLED");
		}
		i++;
	}
	env->tab_int[i + 1] = 0;
	ft_fill_list(env);
	return (0);
}

/*
** function that fills the tab with the info of the map
*/

void			ft_fill_list(t_data *env)
{
	int			x;
	int			y;
	char		**map_split;

	x = 0;
	y = 0;
	map_split = NULL;
	while (y < env->line)
	{
		map_split = ft_strsplit(env->map[y], ' ');
		while (x < env->column)
		{
			env->tab_int[y][x].z = ft_atoi(map_split[x]);
			env->tab_int[y][x].x = env->xdecale;
			env->tab_int[y][x].y = env->ydecale;
			ft_strdel(&map_split[x]);
			env->xdecale += env->cube;
			x++;
		}
		ft_free_tab_data(map_split, x);
		env->xdecale = 0;
		env->ydecale += env->cube;
		x = 0;
		y++;
	}
}

/*
** function that adds back the '\n' at the end of line
** in the GNL
*/

char			*ft_back_n(char *map, int fd, t_data *env)
{
	char		*tmp;
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(map);
	if (!(tmp = ft_strnew(len + 1)))
	{
		ft_exit(fd, env, "malloc():\tFAILLED");
		return (NULL);
	}
	while (map[i] != '\0')
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = '\n';
	i++;
	tmp[i] = '\0';
	ft_strdel(&map);
	return (tmp);
}
