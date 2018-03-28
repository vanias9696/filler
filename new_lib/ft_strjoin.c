/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:52:07 by ismus             #+#    #+#             */
/*   Updated: 2017/11/04 16:52:08 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		l;
	int		i;

	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1);
	l = l + ft_strlen(s2);
	new = (char *)malloc(l + 1);
	if (!new)
		return (0);
	i = 0;
	while (*s1)
	{
		new[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new[i] = *s2;
		i++;
		s2++;
	}
	new[i] = '\0';
	return (new);
}
