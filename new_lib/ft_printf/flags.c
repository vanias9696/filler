/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:15:46 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 17:15:46 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags_id_wide(t_plist *par, char *s)
{
	char *free_s;

	free_s = s;
	if (ft_while_not_n(par->flag, '-') >= 0)
		s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, -1);
	else if (ft_while_not_n(par->flag, '0') >= 0)
		s = ft_n_and_s('0', par->wide - ft_strlen(s), s, 1);
	else
		s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, 1);
	free(free_s);
	if (ft_while_not_n(par->flag, '0') >= 0 && ft_while_not_n(par->flag, '+')
		>= 0 && ft_while_not_n(par->flag, '-') <= 0)
		s[0] = '+';
	else if (ft_while_not_n(par->flag, '0') >= 0 &&
		ft_while_not_n(par->flag, ' ') >= 0 &&
		ft_while_not_n(par->flag, '+') < 0)
		s[0] = ' ';
	return (s);
}

static char	*plus(char *s)
{
	char *free_s;

	free_s = s;
	s = ft_n_and_s('+', 1, s, 1);
	free(free_s);
	return (s);
}

static char	*flags_id_without_acc(t_plist *par, char *s)
{
	char *free_s;

	free_s = s;
	if (ft_while_not_n(par->flag, '+') >= 0 && (ft_while_not_n(par->flag, '0')
		< 0 || ft_while_not_n(par->flag, '-') >= 0))
	{
		s = ft_strcjoin(s, '+', -1);
		free(free_s);
	}
	else if (ft_while_not_n(par->flag, ' ') >= 0 &&
		ft_while_not_n(par->flag, '+') < 0 && (ft_while_not_n(par->flag, '0')
		< 0 || ft_while_not_n(par->flag, '-') >= 0 ||
		par->wide < (int)ft_strlen(s)))
	{
		s = ft_strcjoin(s, ' ', -1);
		free(free_s);
	}
	free_s = s;
	if (par->wide > (int)ft_strlen(s))
		return (flags_id_wide(par, s));
	else if (ft_while_not_n(par->flag, '+') >= 0 && ft_while_not_n(s, '+') < 0)
		s = plus(s);
	return (s);
}

char		*flags_id(t_plist *par, char *s)
{
	char *free_s;

	if (s[0] == '-')
		return (flags_mid(par, s));
	if (par->if_acc == 1)
	{
		if (par->accuracy == 0 && s[0] == '0' && s[1] == '\0')
			s[0] = '\0';
		while (ft_while_not_n(par->flag, '0') >= 0)
			par->flag[ft_while_not_n(par->flag, '0')] = '.';
		if (par->accuracy > (int)ft_strlen(s))
		{
			free_s = s;
			s = ft_n_and_s('0', par->accuracy - ft_strlen(s), s, 1);
			free(free_s);
		}
	}
	s = flags_id_without_acc(par, s);
	return (s);
}
