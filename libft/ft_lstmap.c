/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:47:30 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/24 10:08:55 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!(lst))
		return (NULL);
	if (!(tmp = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	tmp = f(tmp);
	tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
