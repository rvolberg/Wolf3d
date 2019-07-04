/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:55:18 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 16:16:27 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			x = i;
		i++;
	}
	if (x == 0 && s[i] != c && s[x] != c)
		return (NULL);
	else if (x == 0 && s[x] == c)
		return ((char *)s);
	else if (s[i] == c)
		return ((char *)s + i);
	else
		return ((char *)s + x);
}
