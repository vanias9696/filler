/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:53:31 by ismus             #+#    #+#             */
/*   Updated: 2017/11/07 17:53:32 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!lst || !f)
		return (0);
	new = f(lst);
	temp = new;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (!temp->next)
			return (0);
		temp = temp->next;
	}
	return (new);
}
