/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_mid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:46:45 by ismus             #+#    #+#             */
/*   Updated: 2018/03/21 14:46:45 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags_mid_acc(t_plist *par, char *s)
{
	char *free_s;

	while (ft_while_not_n(par->flag, '0') >= 0)
		par->flag[ft_while_not_n(par->flag, '0')] = '.';
	if (par->accuracy > (int)ft_strlen(s) - 1)
	{
		s[0] = '0';
		free_s = s;
		s = ft_n_and_s('0', par->accuracy - ft_strlen(s) + 1, s, 1);
		s[0] = '-';
		free(free_s);
	}
	return (s);
}

char		*flags_mid(t_plist *par, char *s)
{
	char *free_s;

	if (par->if_acc == 1)
		s = flags_mid_acc(par, s);
	if (par->wide > (int)ft_strlen(s))
	{
		free_s = s;
		if (ft_while_not_n(par->flag, '-') >= 0)
			s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, -1);
		else if (ft_while_not_n(par->flag, '0') >= 0)
		{
			s[ft_while_not_n(s, '-')] = '0';
			s = ft_n_and_s('0', par->wide - ft_strlen(s), s, 1);
			s[0] = '-';
		}
		else
			s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, 1);
		free(free_s);
	}
	return (s);
}
