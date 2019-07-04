/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:15:53 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/22 18:35:14 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n / 10 * -1, fd);
		ft_putnbr_fd(n % 10 * -1, fd);
	}
	else if (n >= -9 && n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
		ft_putchar_fd(n + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
