/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:07:47 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/21 16:51:14 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		*dst;

	dst = dest;
	str = src;
	i = 0;
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
