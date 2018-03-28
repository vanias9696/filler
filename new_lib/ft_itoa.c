/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:30:07 by ismus             #+#    #+#             */
/*   Updated: 2017/11/03 15:30:09 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(char *a, int len, intmax_t n, int flag)
{
	int i;

	i = 0;
	while (len - 1 - i >= 0)
	{
		a[len - 1 - i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	if (flag == 1)
		a[0] = '-';
	a[len] = '\0';
	return (a);
}

char		*ft_itoa(intmax_t n)
{
	int			flag;
	char		*a;
	int			len;
	intmax_t	c;

	flag = 0;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		len++;
		flag = 1;
	}
	c = n;
	while (c > 0)
	{
		len++;
		c = c / 10;
	}
	a = (char *)malloc(len + 1);
	if (a == 0)
		return (0);
	return (fill(a, len, n, flag));
}
