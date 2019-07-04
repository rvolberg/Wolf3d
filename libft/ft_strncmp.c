/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:19:38 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 17:29:37 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int b;

	i = 0;
	b = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] != '\0' && s2[b] != '\0' && s1[i] == s2[b])
	{
		i++;
		b++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[b]);
}
