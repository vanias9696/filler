/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:32:42 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 17:32:43 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	modif_s_wide(t_plist *par, char *s)
{
	char	*free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		free_s = ft_by_n(par->wide - ft_strlen(s), ' ');
		ft_putstr(s);
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - ft_strlen(s), '0');
		ft_putstr(free_s);
		ft_putstr(s);
	}
	else
	{
		free_s = ft_by_n(par->wide - ft_strlen(s), ' ');
		ft_putstr(free_s);
		ft_putstr(s);
	}
	free(free_s);
	return (par->wide);
}

int			modif_s(t_plist *par, va_list arg)
{
	char	*s;
	char	*st;

	s = va_arg(arg, char *);
	if (s == 0)
		return (modif_s0(par));
	if (par->if_acc == 1 && par->accuracy < (int)ft_strlen(s))
	{
		st = (char *)malloc(par->accuracy + 1);
		st = ft_strncpy(st, s, par->accuracy);
		st[par->accuracy] = '\0';
		s = st;
	}
	if (par->wide > (int)ft_strlen(s))
		return (modif_s_wide(par, s));
	ft_putstr(s);
	return (ft_strlen(s));
}
