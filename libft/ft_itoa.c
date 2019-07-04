/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:40:16 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/21 17:51:26 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static		*ft_itoaneg(int n)
{
	char			*dst;
	unsigned int	len;
	int				i;
	int				nb;

	i = 1;
	len = 2;
	nb = n;
	while (nb < -9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(dst = ft_strnew(len)))
		return (0);
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 * -1 + '0';
		n = n / 10;
		i--;
	}
	dst[0] = '-';
	return (dst);
}

char			*ft_itoa(int n)
{
	char			*dst;
	unsigned int	len;
	int				i;
	int				nb;

	i = 0;
	nb = n;
	len = 1;
	if (n < 0)
		return (ft_itoaneg(n));
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	if (!(dst = ft_strnew(len)))
		return (0);
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (dst);
}
