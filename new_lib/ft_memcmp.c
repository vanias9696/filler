/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:56:56 by ismus             #+#    #+#             */
/*   Updated: 2017/10/26 18:56:57 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ar1, const void *ar2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!ar1 && !ar2 && !n)
		return (0);
	s1 = (unsigned char *)ar1;
	s2 = (unsigned char *)ar2;
	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	return (i == n ? 0 : s1[i] - s2[i]);
}
