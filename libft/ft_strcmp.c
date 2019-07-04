/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:10:17 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 15:11:49 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (s1[i] == s2[b] && s1[i] != '\0' && s2[b] != '\0')
	{
		i++;
		b++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[b]);
}
