/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:20:12 by ismus             #+#    #+#             */
/*   Updated: 2017/10/25 18:20:13 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while (str1[i + j] != '\0' && i + j < len && str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		i++;
	}
	if (str2[0] == '\0')
		return ((char *)str1);
	return (0);
}
