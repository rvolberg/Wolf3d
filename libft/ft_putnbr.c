/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:24:17 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 18:34:23 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < -9)
	{
		ft_putchar('-');
		ft_putnbr(n / 10 * -1);
		ft_putnbr(n % 10 * -1);
	}
	else if (n >= -9 && n < 0)
	{
		n = n * -1;
		ft_putchar('-');
		ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}
