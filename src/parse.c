/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:37:53 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 13:10:55 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that verifies if all the char in the line
** of the map are valid.
*/

void				ft_charcheck(char *line, int fd, t_data *env)
{
	int				i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '\n'
			&& line[i] != ' ' && line[i] != '\0')
		{
			free(line);
			ft_exit(fd, env, "Error 1:\tinvalid map");
		}
		i++;
	}
}

/*
** function that verifies that all the 0 and 1 are
** correctly separated by ' '
*/

void				ft_placecheck(char *str, int fd, t_data *env)
{
	int				i;

	i = 0;
	if (str[0] != '1')
		ft_exit(fd, env, "Error 2:\tinvalid map");
	while (str[i] != '\0')
	{
		if ((str[i] == '0') || (str[i] == '1'))
		{
			if ((str[i + 1] != ' ') && (str[i + 1] != '\0'))
				ft_exit(fd, env, "Error 2:\tinvalid map");
		}
		if (str[i] == ' ')
		{
			if ((str[i + 1] != '1') && (str[i + 1] != '0'))
				ft_exit(fd, env, "Error 2:\tinvalid map");
		}
		i++;
	}
}

/*
** function that check if the construct
** of a line of the map is valid
*/

void				ft_checkwall(char **map, t_data *env)
{
	int				len;
	int				x;
	int				y;

	y = 0;
	x = 0;
	len = ft_strlen(map[0]);
	while (map[0][x] != '\0')
	{
		if (map[0][x] != '1' && map[0][x] != ' ')
			ft_exit(env->fd, env, "Error 3:\tinvalid map");
		if (map[0][x] == '1')
			env->column++;
		x++;
	}
	ft_cw_support(map, env, len, y);
	if (env->column > 107 || env->line > 67)
		ft_exit(env->fd, env, "Error:\t[map] out of parameters");
	if (env->column < 3 || env->line < 3)
		ft_exit(env->fd, env, "Error:\t[map] out of parameters");
}

/*
** function that support ft_checkwall
*/

void				ft_cw_support(char **map, t_data *env, int len, int y)
{
	int				x;
	int				space;

	while (map[y] != NULL)
	{
		if (map[y][0] == '1')
			env->line++;
		if ((map[y][0] != '1') || (map[y][len - 1] != '1'))
			ft_exit(env->fd, env, "Error 3:\tinvalid map");
		space = 0;
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0')
				space++;
			if (map[y + 1] == NULL)
				if (map[y][x] != '1' && map[y][x] != ' ')
					ft_exit(env->fd, env, "Error 3:\tinvalid map");
			x++;
		}
		if ((x != len) || ((space == 0) && (y != 0) && (map[y + 1] != NULL)))
			ft_exit(env->fd, env, "Error 3:\tinvalid map");
		y++;
	}
}
