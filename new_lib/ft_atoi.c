/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:50:46 by ismus             #+#    #+#             */
/*   Updated: 2017/10/25 15:24:50 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	long_min_max(const char *str, int i, int flag)
{
	int		l;

	l = 0;
	while (str[i] == '0')
		i++;
	while (str[i + l] < 58 && str[i + l] > 47)
		l++;
	if (l > 19)
		return (flag == 1 ? -1 : 0);
	if (l == 19)
	{
		if (flag == 1 && ft_strcmp(str + i, "9223372036854775807") > 0)
			return (-1);
		if (flag == -1 && ft_strcmp(str + i, "9223372036854775808") > 0)
			return (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int i;
	int flag;
	int a;

	i = 0;
	a = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\f' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (long_min_max(str, i, flag) == -1 || long_min_max(str, i, flag) == 0)
		return (long_min_max(str, i, flag));
	while (str[i] < 58 && str[i] > 47)
		a = str[i++] - '0' + a * 10;
	return (flag == -1 ? -a : a);
}
