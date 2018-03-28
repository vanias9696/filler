/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:25:24 by ismus             #+#    #+#             */
/*   Updated: 2017/11/07 17:25:25 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *nex;

	if (alst && *alst && del)
	{
		temp = *alst;
		while (temp->next)
		{
			nex = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = nex;
		}
		del(temp->content, temp->content_size);
		free(temp);
		*alst = NULL;
	}
}
