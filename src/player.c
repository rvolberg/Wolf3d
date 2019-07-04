/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:38:16 by rvolberg          #+#    #+#             */
/*   Updated: 2019/03/15 09:21:46 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf.h"

/*
** function that select the first available
** placement in the map for the player.
*/

int				ft_place_perso(t_data *env)
{
	while (env->yi < env->line)
	{
		while (env->xi < env->column)
		{
			if (env->tab_int[env->yi][env->xi].z == 0)
				return (1);
			env->xi++;
		}
		env->xi = 0;
		env->yi++;
	}
	return (0);
}
