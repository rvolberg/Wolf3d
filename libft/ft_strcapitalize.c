/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:49:12 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/24 11:05:51 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int b;
	int c;

	if (!(str))
		return (0);
	str = ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] >= 'a' && str[i] <= 'z')
		{
			b = i;
			while (str[i] >= 'a' && str[i] <= 'z')
				i++;
			c = b - 1;
			if (str[c] >= '0' && str[c] <= '9')
				str[b] = str[b];
			else
				str[b] = str[b] - 32;
		}
		i++;
	}
	return (str);
}
