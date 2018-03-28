/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:53:23 by ismus             #+#    #+#             */
/*   Updated: 2017/10/26 17:53:24 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *s, size_t n)
{
	char	*t1;
	char	*t2;

	t1 = (char *)dest;
	t2 = (char *)s;
	if (dest < s)
		return (ft_memcpy(dest, s, n));
	while (n--)
	{
		t1[n] = t2[n];
	}
	return (dest);
}
