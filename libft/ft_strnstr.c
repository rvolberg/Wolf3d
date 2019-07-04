/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:12:24 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 14:58:44 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	p;
	int				o;
	int				g;

	p = 0;
	o = 0;
	if (needle[o] == '\0')
		return ((char*)haystack);
	while (p < len && haystack[p] != '\0')
	{
		g = p;
		while (haystack[p] == needle[o] && p < len)
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
