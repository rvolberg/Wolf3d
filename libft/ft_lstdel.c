/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:16:26 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 16:25:45 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *start;
	t_list *tmp;

	if (!(*alst) || !(del))
		return ;
	start = *alst;
	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		free(*alst);
		(*alst) = tmp;
	}
	start = NULL;
}
