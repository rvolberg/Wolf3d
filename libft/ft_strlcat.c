/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:15 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/24 13:06:39 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t p;

	i = 0;
	p = ft_strlen(dest);
	if (p >= size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && (p + i + 1) < size)
	{
		dest[i + p] = src[i];
		i++;
	}
	dest[i + p] = '\0';
	return (ft_strlen(src) + p);
}
