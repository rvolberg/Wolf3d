/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:24:21 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 14:49:49 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		p;
	int		o;
	int		g;

	p = 0;
	o = 0;
	if (needle[o] == '\0')
		return ((char *)haystack);
	while (haystack[p] != '\0')
	{
		g = p;
		while (haystack[p] == needle[o])
		{
			p++;
			o++;
			if (needle[o] == '\0')
				return ((char *)haystack + g);
		}
		p = g;
		p++;
		o = 0;
	}
	return (NULL);
}
