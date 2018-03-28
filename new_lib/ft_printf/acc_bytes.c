/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acc_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:20:05 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 18:20:06 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		n_byte(unsigned int i)
{
	int n;

	if (i < 128)
		n = 1;
	if (i > 127 && i < 2048)
		n = 2;
	if (i > 2047 && i < 65536)
		n = 3;
	if (i > 65535 && i < 1114112)
		n = 4;
	return (n);
}

int		ac_n_bytes(unsigned int *s, int acc)
{
	int i;
	int bytes;
	int n;

	i = 0;
	bytes = 0;
	while (s[i] && acc >= 0)
	{
		n = n_byte(s[i]);
		if (bytes + n <= acc)
			bytes = bytes + n;
		else
			acc = -1;
		i++;
	}
	return (bytes);
}

int		n_bytes(unsigned int *s)
{
	int i;
	int bytes;

	i = 0;
	bytes = 0;
	while (s[i])
	{
		if (s[i] < 128)
			bytes = bytes + 1;
		if (s[i] > 127 && s[i] < 2048)
			bytes = bytes + 2;
		if (s[i] > 2047 && s[i] < 65536)
			bytes = bytes + 3;
		if (s[i] > 65535 && s[i] < 1114112)
			bytes = bytes + 4;
		i++;
	}
	return (bytes);
}

int		type_n(int k_ret, va_list arg)
{
	int *i;

	i = va_arg(arg, int *);
	*i = k_ret;
	return (0);
}
