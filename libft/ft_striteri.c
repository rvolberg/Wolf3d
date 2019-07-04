/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:16:23 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 19:47:27 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int a;
	int b;
	int i;

	i = 0;
	a = 0;
	if (s != NULL && f != NULL)
	{
		b = ft_strlen(s);
		while (a < b)
		{
			(*f)(i, s);
			s++;
			a++;
			i++;
		}
	}
}
