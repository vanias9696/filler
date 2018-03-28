/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:04:09 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 19:04:10 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*p_accu(t_plist *par, char *s, unsigned long int i)
{
	int		k;
	char	*free_s;

	if (par->if_acc == 1)
	{
		while (ft_while_not_n(par->flag, '0') >= 0)
		{
			k = ft_while_not_n(par->flag, '0');
			par->flag[k] = '.';
		}
		if (par->accuracy > (int)ft_strlen(s))
		{
			free_s = s;
			s = ft_n_and_s('0', par->accuracy - ft_strlen(s), s, 1);
			free(free_s);
		}
	}
	if (i == 0 && par->if_acc == 1)
	{
		free(s);
		s = ft_by_n(par->accuracy, '0');
	}
	return (s);
}

static void	flads_for_p(t_plist *par, char *s)
{
	char	*free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		ft_putstr("0x");
		ft_putstr(s);
		free_s = ft_by_n(par->wide - ft_strlen(s) - 2, ' ');
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		ft_putstr("0x");
		free_s = ft_by_n(par->wide - ft_strlen(s) - 2, '0');
		ft_putstr(free_s);
		ft_putstr(s);
	}
	else
	{
		free_s = ft_by_n(par->wide - ft_strlen(s) - 2, ' ');
		ft_putstr(free_s);
		ft_putstr("0x");
		ft_putstr(s);
	}
	free(free_s);
	free(s);
}

int			modif_p(t_plist *par, va_list arg)
{
	unsigned long int	i;
	char				*s;

	i = va_arg(arg, unsigned long int);
	s = ft_utoa_base(i, 16);
	s = p_accu(par, s, i);
	if (par->wide > (int)ft_strlen(s) + 2)
	{
		flads_for_p(par, s);
		return (par->wide);
	}
	ft_putstr("0x");
	ft_putstr(s);
	i = ft_strlen(s) + 2;
	free(s);
	return (i);
}
