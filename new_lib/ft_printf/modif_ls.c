/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:58:34 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 16:58:34 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	while_acc(int bytes, t_plist *null, unsigned int *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (bytes > 0)
	{
		if (n_byte(s[i]) > bytes)
			bytes = 0;
		else
		{
			n = n + n_byte(s[i]);
			bytes = bytes - n_byte(s[i]);
			unicode(s[i], null);
			i++;
		}
	}
	return (n);
}

static int	pri_acc_unic(unsigned int *s, t_plist *par)
{
	t_plist	*null;
	int		n;

	null = (t_plist *)malloc(sizeof(t_plist));
	null->flag = ft_strnew(1);
	null->spec = ft_strnew(1);
	null->if_acc = 0;
	null->wide = 0;
	ft_bzero(par->flag, ft_strlen(par->flag));
	n = while_acc(par->accuracy, null, s);
	free(null->spec);
	free(null->flag);
	free(null);
	return (n);
}

static int	acc_unic(unsigned int *s, t_plist *par, int bytes)
{
	char	*free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		pri_acc_unic(s, par);
		free_s = ft_by_n(par->wide - bytes, ' ');
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - bytes, '0');
		ft_putstr(free_s);
		pri_acc_unic(s, par);
	}
	else
	{
		free_s = ft_by_n(par->wide - bytes, ' ');
		ft_putstr(free_s);
		pri_acc_unic(s, par);
	}
	free(free_s);
	return (par->wide);
}

static int	print_wide_str(unsigned int *s, t_plist *par, int bytes)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		free_s = ft_by_n(par->wide - bytes, ' ');
		str_unicode(s);
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - bytes, '0');
		ft_putstr(free_s);
		str_unicode(s);
	}
	else
	{
		free_s = ft_by_n(par->wide - bytes, ' ');
		ft_putstr(free_s);
		str_unicode(s);
	}
	free(free_s);
	return (par->wide);
}

int			modif_ls(t_plist *par, va_list arg)
{
	int				i;
	int				bytes;
	unsigned int	*s;

	i = 0;
	s = va_arg(arg, unsigned int *);
	if (s == 0 || (par->if_acc == 1 && par->accuracy == 0))
		return (modif_s0(par));
	bytes = n_bytes(s);
	if (par->if_acc != 1 || par->accuracy >= bytes)
	{
		if (par->wide > bytes)
			return (print_wide_str(s, par, bytes));
		str_unicode(s);
		return (bytes);
	}
	if ((par->if_acc == 1 && par->wide < par->accuracy) ||
		(par->if_acc == 0 && par->wide < bytes))
		return (pri_acc_unic(s, par));
	return (acc_unic(s, par, ac_n_bytes(s, par->accuracy)));
}
