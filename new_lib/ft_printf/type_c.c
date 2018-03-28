/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:43:48 by ismus             #+#    #+#             */
/*   Updated: 2018/03/14 17:43:49 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	modif_widec(t_plist *par, char c)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		free_s = ft_by_n(par->wide - 1, ' ');
		ft_putchar(c);
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 1, '0');
		ft_putstr(free_s);
		ft_putchar(c);
	}
	else
	{
		free_s = ft_by_n(par->wide - 1, ' ');
		ft_putstr(free_s);
		ft_putchar(c);
	}
	free(free_s);
	return (par->wide);
}

int			modif_c(t_plist *par, va_list arg)
{
	int		c;

	c = va_arg(arg, int);
	if (c == 0)
		c = '\0';
	if (par->wide > 1)
		return (modif_widec(par, c));
	ft_putchar(c);
	return (1);
}
