/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:21:00 by ismus             #+#    #+#             */
/*   Updated: 2017/10/26 18:21:03 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *t, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	if (t == NULL && n == 0 && c == 0)
		return (0);
	s = (unsigned char*)t;
	while (s[i] != (unsigned char)c && i < n - 1)
		i++;
	if (s[i] == (unsigned char)c && i < n)
	{
		return ((void *)t + i);
	}
	return (0);
}
