/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:56:33 by ismus             #+#    #+#             */
/*   Updated: 2018/02/09 14:56:35 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	modif(t_plist *par, va_list arg, char type)
{
	int i;
	int n;

	n = ft_while_not_n(par->spec, 'h');
	i = ft_while_not_n(par->spec, 'l');
	if (ft_while_not_n(par->spec, 't') >= 0)
		return (modif_z(par, arg, type));
	if (ft_while_not_n(par->spec, 'z') >= 0)
		return (modif_z(par, arg, type));
	if (ft_while_not_n(par->spec, 'j') >= 0)
		return (modif_j(par, arg, type));
	else if (i >= 0)
		if (par->spec[i + 1] == 'l')
			return (modif_ll(par, arg, type));
		else
			return (modif_l(par, arg, type));
	else if (n >= 0)
	{
		if (par->spec[n + 1] != 'h')
			return (modif_h(par, arg, type));
		else
			return (modif_hh(par, arg, type));
	}
	return (modif_idoux(par, arg, type));
}

static int	type_else_0(t_plist *par)
{
	char	*s;
	int		i;

	if (ft_while_not_n(par->flag, '-') >= 0)
		s = ft_by_n(par->wide - 1, ' ');
	else if (ft_while_not_n(par->flag, '0') >= 0)
		s = ft_by_n(par->wide - 1, '0');
	else
		s = ft_by_n(par->wide - 1, ' ');
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}

static void	type_else_wide(t_plist *par, char c)
{
	char *s;

	if (ft_while_not_n(par->flag, '0') >= 0)
	{
		s = ft_by_n(par->wide - 1, '0');
		ft_putstr(s);
		ft_putchar(c);
	}
	else
	{
		s = ft_by_n(par->wide - 1, ' ');
		ft_putstr(s);
		ft_putchar(c);
	}
	free(s);
}

static int	type_else(t_plist *par, char c)
{
	char	*s;

	if (par->wide > 1 && c != '\0')
	{
		if (ft_while_not_n(par->flag, '-') >= 0)
		{
			ft_putchar(c);
			s = ft_by_n(par->wide - 1, ' ');
			ft_putstr(s);
			free(s);
		}
		else
			type_else_wide(par, c);
		return (par->wide);
	}
	else if (par->wide > 1 && c == '\0')
		return (type_else_0(par));
	else if (c == '\0')
		return (0);
	ft_putchar(c);
	return (1);
}

int			type_defin(t_plist *par, va_list arg, char type, int k_ret)
{
	if (type == 'n')
		return (type_n(k_ret, arg));
	else if (type == 'd' || type == 'i' || type == 'o' ||
		type == 'u' || type == 'x' || type == 'X')
		return (modif(par, arg, type));
	else if (type == 'D' || type == 'U' || type == 'O')
		return (modif_l(par, arg, type + 32));
	else if (type == 'C' || (type == 'c' &&
		ft_while_not_n(par->spec, 'l') >= 0))
		return (modif_lc(par, arg));
	else if (type == 'S' || (type == 's' &&
		ft_while_not_n(par->spec, 'l') >= 0))
		return (modif_ls(par, arg));
	else if (type == 'c')
		return (modif_c(par, arg));
	else if (type == 's')
		return (modif_s(par, arg));
	else if (type == 'p')
		return (modif_p(par, arg));
	return (type_else(par, type));
}
