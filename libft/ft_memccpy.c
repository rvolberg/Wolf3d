/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:51:28 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 10:06:17 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*mem;
	unsigned char			x;
	const unsigned char		*tmp;

	x = c;
	tmp = src;
	mem = dest;
	i = 0;
	while (i < n)
	{
		mem[i] = tmp[i];
		if (tmp[i] == x)
		{
			mem[i] = tmp[i];
			i++;
			return (mem + i);
		}
		i++;
	}
	return (NULL);
}
