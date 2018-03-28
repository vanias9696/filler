/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:44:25 by ismus             #+#    #+#             */
/*   Updated: 2017/11/07 16:44:26 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list *t;

	t = (t_list *)malloc(sizeof(t_list));
	if (t == 0)
		return (0);
	if (content == 0)
	{
		t->content = NULL;
		t->content_size = 0;
	}
	else
	{
		t->content = malloc(size);
		if (t->content == 0)
		{
			free(t);
			return (0);
		}
		ft_memcpy(t->content, content, size);
		t->content_size = size;
	}
	t->next = NULL;
	return (t);
}
