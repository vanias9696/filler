/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:50:04 by ismus             #+#    #+#             */
/*   Updated: 2018/01/27 16:50:05 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fl_width_acc(char *flag, va_list arg, int k, int k_ret)
{
	t_plist	*param;

	param = (t_plist *)malloc(sizeof(t_plist));
	param->spec = ft_strdup("\0");
	param->flag = ft_strdup("\0");
	param->if_acc = 0;
	param->wide = 0;
	while (flag[k] == '-' || flag[k] == '+' || flag[k] == ' ' ||
		flag[k] == '#' || flag[k] == '0' || flag[k] == '.' ||
		(flag[k] <= '9' && flag[k] >= '0') || flag[k] == 'l' ||
		flag[k] == 'h' || flag[k] == 'j' || flag[k] == 'z' ||
		flag[k] == '*' || flag[k] == 't')
		k = all_param(flag, k, param, arg);
	k = type_defin(param, arg, flag[k], k_ret);
	free(param->spec);
	free(param->flag);
	free(param);
	return (k);
}

static int	num_i(char *flag, int k)
{
	while (flag[k] == '-' || flag[k] == '+' || flag[k] == ' ' ||
		flag[k] == '#' || flag[k] == '0' || flag[k] == '.' || flag[k] == 't'
		|| (flag[k] <= '9' && flag[k] >= '0') || flag[k] == 'l' ||
		flag[k] == 'h' || flag[k] == 'j' || flag[k] == 'z' || flag[k] == '*')
	{
		if (flag[k] == '-' || flag[k] == '+' || flag[k] == ' '
			|| flag[k] == '#' || flag[k] == '0' || flag[k] == '*' ||
			flag[k] == 'l' || flag[k] == 'h' || flag[k] == 'j' ||
			flag[k] == 'z' || flag[k] == 't')
			k++;
		else if (flag[k] <= '9' && flag[k] >= '0')
			while (flag[k] <= '9' && flag[k] >= '0')
				k++;
		else if (flag[k] == '.' && k++)
		{
			if (flag[k] == '*')
				k++;
			else
				while (flag[k] <= '9' && flag[k] >= '0')
					k++;
		}
	}
	if (flag[k] == '\0')
		return (k);
	return (k + 1);
}

static int	find_percent(char *format, va_list arg, int i)
{
	int k_ret;

	k_ret = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i++]);
			k_ret++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar(format[i]);
			i = i + 2;
			k_ret++;
		}
		else
		{
			k_ret = k_ret + fl_width_acc(format, arg, i + 1, k_ret);
			i = num_i(format, i + 1);
		}
	}
	return (k_ret);
}

int			ft_printf(char *format, ...)
{
	va_list arg;
	int		i;

	i = 0;
	va_start(arg, format);
	i = find_percent(format, arg, i);
	va_end(arg);
	return (i);
}
