/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:23:44 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 10:55:45 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*d1;
	const char			*temp;

	d1 = dest;
	temp = src;
	i = 0;
	if (temp > d1)
	{
		while (i < n)
		{
			d1[i] = temp[i];
			i++;
		}
	}
	else if (temp < d1)
	{
		while (n-- > 0)
			d1[n] = temp[n];
	}
	return (d1);
}
