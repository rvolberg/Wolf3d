/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:07:33 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 11:47:22 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	size_t				b;
	const unsigned char	*s11;
	const unsigned char	*s22;

	s11 = s1;
	s22 = s2;
	i = 0;
	b = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s11[i] == s22[b])
	{
		i++;
		b++;
	}
	return (s11[i] - s22[b]);
}
