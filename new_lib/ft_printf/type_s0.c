/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:53:25 by ismus             #+#    #+#             */
/*   Updated: 2018/03/21 14:53:26 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	modif_s0_acc_wide(t_plist *par, char *s)
{
	char	*free_s;
	int		l;

	l = ft_strlen(s);
	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		ft_putstr(s);
		free_s = ft_by_n(par->wide - l, ' ');
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - l, '0');
		ft_putstr(free_s);
		ft_putstr(s);
	}
	else
	{
		free_s = ft_by_n(par->wide - l, ' ');
		ft_putstr(free_s);
		ft_putstr(s);
	}
	free(free_s);
}

static int	modif_s0_acc(t_plist *par)
{
	char *s;

	if (par->accuracy <= 6)
	{
		s = (char *)malloc(par->accuracy + 1);
		s = ft_strncpy(s, "(null)", par->accuracy);
		s[par->accuracy] = '\0';
	}
	else
		s = ft_strdup("\0");
	if (par->wide > (int)ft_strlen(s))
		modif_s0_acc_wide(par, s);
	else
	{
		ft_putstr(s);
		free(s);
		return (par->accuracy);
	}
	free(s);
	return (par->wide);
}

static void	modif_s0_print(t_plist *par)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 6, '0');
		ft_putstr(free_s);
		free(free_s);
		ft_putstr("(null)");
	}
	else
	{
		free_s = ft_by_n(par->wide - 6, ' ');
		ft_putstr(free_s);
		free(free_s);
		ft_putstr("(null)");
	}
}

int			modif_s0(t_plist *par)
{
	char *free_s;

	if (par->if_acc != 0)
		return (modif_s0_acc(par));
	if (par->wide > 6)
	{
		if (ft_while_not_n(par->flag, '-') >= 0)
		{
			ft_putstr("(null)");
			free_s = ft_by_n(par->wide - 6, ' ');
			ft_putstr(free_s);
			free(free_s);
		}
		else
			modif_s0_print(par);
		return (par->wide);
	}
	ft_putstr("(null)");
	return (6);
}
