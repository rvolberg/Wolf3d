/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:37:35 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/06 16:16:32 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that init the window
*/

void		ft_init_window(t_data *env)
{
	env->graph->win_ptr = mlx_new_window(env->graph->mlx_ptr,
			env->graph->width, env->graph->height, "Wolf");
	env->graph->img_ptr = mlx_new_image(env->graph->mlx_ptr, env->graph->width,
			env->graph->height);
	env->graph->img = mlx_get_data_addr(env->graph->img_ptr,
			&(env->graph->bpp), &(env->graph->s_l), &(env->graph->endian));
}

/*
** function that launch the window
*/

int			ft_window_output(t_data *env)
{
	new_image(env);
	mlx_key_hook(env->graph->win_ptr, deal_key, env);
	mlx_hook(env->graph->win_ptr, 17, 1L << 17, ft_close, env);
	mlx_hook(env->graph->win_ptr, KEYPRESS, (1L << 0), ft_perso_move, env);
	mlx_loop(env->graph->mlx_ptr);
	return (0);
}

/*
** function that output the menu or the raycasting
*/

void		new_image(t_data *env)
{
	char	*path;

	if (env->menu == 0)
	{
		path = "texture/menu.XPM";
		if ((env->menu1->img_ptr = mlx_xpm_file_to_image(env->graph->mlx_ptr,
						"texture/menu.XPM", &env->width, &env->height)) == NULL)
			env->menu1->img = mlx_get_data_addr(env->menu1->img_ptr,
					&(env->menu1->bpp), &(env->menu1->s_l),
					&(env->menu1->endian));
		mlx_put_image_to_window(env,
				env->graph->win_ptr, env->menu1->img_ptr, 0, 0);
		mlx_string_put(env->graph->mlx_ptr, env->graph->win_ptr, 525, 600,
				0Xed2d23, "DURING GAME : PRESS O for OPTIONS");
	}
	else
	{
		if (env->menu != 0)
			mlx_clear_window(env->graph->mlx_ptr, env->graph->win_ptr);
		ft_init_texture(env);
		raycasting(env);
		mlx_put_image_to_window(env, env->graph->win_ptr,
								env->graph->img_ptr, 0, 0);
	}
}
