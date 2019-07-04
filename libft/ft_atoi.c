/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:45:52 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 17:48:09 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_exept(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

int				ft_atoi(const char *nptr)
{
	int i;
	int nb;
	int kind;

	nb = 0;
	i = ft_exept(nptr);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		kind = nptr[i];
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	if (kind == '-')
	{
		nb = nb - nb * 2;
	}
	return (nb);
}
