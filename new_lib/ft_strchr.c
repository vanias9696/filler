/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:25:29 by ismus             #+#    #+#             */
/*   Updated: 2017/10/27 17:25:30 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			return ((char *)str + i);
		else
			i++;
	}
	if (s == '\0')
		return ((char *)str + i);
	return (0);
}
