/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:24:32 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 19:56:43 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*dst;
	unsigned int		i;
	unsigned int		b;

	i = 0;
	b = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
					+ 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
	{
		dst[i] = s2[b];
		i++;
		b++;
	}
	dst[i] = '\0';
	return (dst);
}
