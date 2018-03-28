/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:43:27 by ismus             #+#    #+#             */
/*   Updated: 2018/03/15 14:43:28 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_wide_acc(t_plist *param, char *flag, int k, va_list arg)
{
	if (flag[k] <= '9' && flag[k] >= '0')
	{
		param->wide = ft_atoi(flag + k);
		while (flag[k] <= '9' && flag[k] >= '0')
			k++;
	}
	else if (flag[k] == '.')
	{
		param->if_acc = 1;
		if (flag[k + 1] == '*')
		{
			param->accuracy = va_arg(arg, int);
			if (param->accuracy < 0)
				param->if_acc = 0;
			k = k + 2;
		}
		else
		{
			param->accuracy = ft_atoi(++k + flag);
			while (flag[k] <= '9' && flag[k] >= '0')
				k++;
		}
	}
	return (k);
}

static int	wide_zv(t_plist *param, va_list arg)
{
	char *free_s;

	param->wide = va_arg(arg, int);
	if (param->wide < 0)
	{
		param->wide = param->wide * -1;
		free_s = param->flag;
		param->flag = ft_strcjoin(param->flag, '-', 1);
		free(free_s);
	}
	return (1);
}

int			all_param(char *flag, int k, t_plist *param, va_list arg)
{
	char *free_s;

	if (flag[k] == '-' || flag[k] == '+' || flag[k] == ' '
		|| flag[k] == '#' || flag[k] == '0')
	{
		free_s = param->flag;
		param->flag = ft_strcjoin(param->flag, flag[k++], 1);
		free(free_s);
	}
	else if (flag[k] == '*')
		k = k + wide_zv(param, arg);
	else if ((flag[k] <= '9' && flag[k] >= '0') || flag[k] == '.')
		k = flag_wide_acc(param, flag, k, arg);
	else
	{
		free_s = param->spec;
		param->spec = ft_strcjoin(param->spec, flag[k++], 1);
		free(free_s);
	}
	return (k);
}
