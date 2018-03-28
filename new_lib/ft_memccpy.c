/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:16:37 by ismus             #+#    #+#             */
/*   Updated: 2017/10/26 17:16:39 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)dest;
	t2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t1[i] = t2[i];
		if (t2[i] == (unsigned char)c)
			return (t1 + i + 1);
		i++;
	}
	return (0);
}
