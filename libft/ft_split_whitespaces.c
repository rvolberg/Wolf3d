/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:30:16 by tlaberro          #+#    #+#             */
/*   Updated: 2019/03/06 16:09:24 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_copyword(char *str, int i, int n)
{
	char	*dest;
	int		h;

	h = 0;
	dest = (char *)malloc((i - n + 1) * sizeof(*dest));
	while (n < i)
	{
		dest[h] = str[n];
		h++;
		n++;
	}
	dest[h] = '\0';
	return (dest);
}

static int		ft_skip(char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	return (i);
}

char			**ft_split_whitespaces(char *str)
{
	int		i;
	int		n;
	int		m;
	char	**dest;

	m = 0;
	dest = (char **)malloc(sizeof(char *) * ft_strlen(str) + 1);
	i = ft_skip(str, 0);
	while (str[i] != '\0')
	{
		n = i;
		while (str[i] != '\n' && str[i] != '\t' && str[i] != ' '
			&& str[i] != '\0')
			i++;
		dest[m] = ft_copyword(str, i, n);
		m++;
		i = ft_skip(str, i);
	}
	dest[m] = 0;
	return (dest);
}
