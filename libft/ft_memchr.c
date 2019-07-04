/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:23:11 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 09:55:12 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	x;
	size_t			i;
	unsigned char	*mem;

	i = 0;
	x = c;
	mem = (unsigned char *)s;
	while (i < n)
	{
		if (mem[i] == x)
			return (mem + i);
		i++;
	}
	return (NULL);
}
