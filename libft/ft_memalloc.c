/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:57:02 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/13 09:00:46 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*t;
	size_t	i;

	i = 0;
	if ((t = malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}
