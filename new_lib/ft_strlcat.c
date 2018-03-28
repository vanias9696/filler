/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:29:36 by ismus             #+#    #+#             */
/*   Updated: 2017/10/26 20:29:37 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t ls;
	size_t ld;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	i = ld;
	if ((int)size < 0)
	{
		while (src[i - ld])
		{
			dst[i] = src[i - ld];
			i++;
		}
		return (ls + ld);
	}
	if (size <= ld)
		return (ls + size);
	while (size > i + 1)
	{
		dst[i] = src[i - ld];
		i++;
	}
	dst[i] = '\0';
	return (ls + ld);
}
