/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:08:50 by ismus             #+#    #+#             */
/*   Updated: 2018/02/09 18:08:51 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*if_n_positive(char *new, char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		new[i++] = *s;
		s++;
	}
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ft_strcjoin(char *s, char c, int n)
{
	char	*new;
	int		l;
	int		i;

	if (!s)
		return (0);
	l = ft_strlen(s);
	new = (char *)malloc(l + 2);
	if (!new)
		return (0);
	if (n > 0)
		new = if_n_positive(new, s, c);
	else
	{
		i = 0;
		new[i++] = c;
		while (*s)
		{
			new[i++] = *s;
			s++;
		}
		new[i] = '\0';
	}
	return (new);
}
