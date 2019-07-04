/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:24:32 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 10:05:53 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_wc(char const *s, char c)
{
	int					i;
	size_t				j;

	j = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static char				**fill_tab(const char *s, char **tab, char c)
{
	unsigned int		i;
	unsigned int		x;
	unsigned int		y;

	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		x = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i != x)
		{
			tab[y] = ft_strsub(s, x, (i - x));
			y++;
		}
	}
	tab[y] = NULL;
	return (tab);
}

char					**ft_strsplit(char const *s, char c)
{
	char				**tab;
	size_t				j;

	tab = NULL;
	if (s)
	{
		j = ft_wc(s, c);
		if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
			return (NULL);
		if (ft_strequ(s, ""))
			tab[0] = NULL;
		else
		{
			tab = fill_tab(s, tab, c);
		}
	}
	return (tab);
}
