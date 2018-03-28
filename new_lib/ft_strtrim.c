/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:31:23 by ismus             #+#    #+#             */
/*   Updated: 2017/11/04 16:31:24 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*new;

	i = 0;
	if (!s)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	l = ft_strlen(s);
	while ((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') && l > 0)
		l--;
	new = (char *)malloc(l + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < l)
	{
		new[i] = *s;
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
