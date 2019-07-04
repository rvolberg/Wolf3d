/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:55:21 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 09:30:52 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*dst;
	int				i;
	unsigned int	start;

	start = 0;
	if (!(s))
		return (NULL);
	i = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	dst = ft_strsub(s, start, ((i - start) + 1));
	return (dst);
}
