/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 03:29:00 by sshin             #+#    #+#             */
/*   Updated: 2016/12/27 08:49:36 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (lst)
	{
		p = f(lst);
		p->next = ft_lstmap(lst->next, f);
		return (p);
	}
	return (NULL);
}
