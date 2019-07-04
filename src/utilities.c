/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:39:23 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/22 13:14:13 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that print a pixel
*/

void			img_pixel(t_data *env, int x, int y, int color)
{
	if (x < 0 || x >= env->width || y < 0 || y >= env->height)
		return ;
	*((int*)(env->graph->img + ((x + y * env->width) * 4))) = color;
}

/*
** function that cleans and delete the window proprely
*/

int				ft_close(t_data *env)
{
	mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
	mlx_destroy_window(env->graph->mlx_ptr, env->graph->win_ptr);
	free_struct(env);
	exit(EXIT_SUCCESS);
}

/*
** function easily quit and close the program
*/

void			ft_exit(int fd, t_data *env, char *str)
{
	close(fd);
	ft_putendl_fd(str, 2);
	free_struct(env);
	exit(EXIT_FAILURE);
}

/*
** function to free a tab with two dimention
*/

void			ft_free_tab_data(char **tab, int i)
{
	int			n;

	n = 0;
	while (n <= i)
	{
		ft_strdel(&tab[n]);
		n++;
	}
	free(tab);
}

/*
** protected open function
*/

int				ft_open(char *str, t_data *env)
{
	int			fd;

	fd = 0;
	if ((fd = open(str, O_RDONLY)) <= 0)
	{
		ft_exit(fd, env, "open():\tFAILLED\n");
	}
	return (fd);
}
