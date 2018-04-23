/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:14:16 by ismus             #+#    #+#             */
/*   Updated: 2018/04/18 15:14:17 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*joinfree(char *s1, char *s2, int n)
{
	char	*new;
	int		l;
	int		i;

	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(l + 1)))
		return (0);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	l = 0;
	while (s2[l])
		new[i++] = s2[l++];
	new[i] = '\0';
	if (n == 3 || n == 1)
		free(s1);
	if (n == 3 || n == 2)
		free(s2);
	return (new);
}
