/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 17:19:26 by ismus             #+#    #+#             */
/*   Updated: 2018/02/11 17:19:27 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(int len, intmax_t n, int flag, int base)
{
	char	*a;
	int		i;
	int		num;

	a = (char *)malloc(len + 1);
	i = 0;
	while (len - 1 - i >= 0)
	{
		num = n % base;
		if (num >= 10)
			a[len - 1 - i] = num + 87;
		else
			a[len - 1 - i] = num + 48;
		n = n / base;
		i++;
	}
	if (flag == 1)
		a[0] = '-';
	a[len] = '\0';
	return (a);
}

char		*ft_itoa_base(intmax_t n, int base)
{
	int			flag;
	int			len;
	intmax_t	c;

	flag = 0;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
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
		c = c / base;
	}
	return (fill(len, n, flag, base));
}
