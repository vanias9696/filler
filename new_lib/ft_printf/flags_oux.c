/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:08:04 by ismus             #+#    #+#             */
/*   Updated: 2018/03/15 15:08:05 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags_oux_acc2(t_plist *par, char type, char *s, int num)
{
	char *free_s;

	free_s = s;
	if (ft_while_not_n(par->flag, '#') >= 0)
	{
		if (type == 'o' && num != 0 && s[0] != '0')
		{
			s = ft_strcjoin(s, '0', -1);
			free(free_s);
		}
		else if ((type == 'x' || type == 'X') && num != 0)
		{
			s = ft_strjoin("0x", s);
			free(free_s);
		}
	}
	return (s);
}

static char	*flags_oux_acc1(t_plist *par, char type, char *s, int num)
{
	char *free_s;

	if (par->accuracy == 0 && num == 0 && ((ft_while_not_n(par->flag, '#')
		< 0 && type == 'o') || type != 'o'))
	{
		free(s);
		s = ft_strdup("\0");
	}
	while (ft_while_not_n(par->flag, '0') >= 0)
		par->flag[ft_while_not_n(par->flag, '0')] = '.';
	free_s = s;
	if (par->accuracy > (int)ft_strlen(s))
	{
		s = ft_n_and_s('0', par->accuracy - ft_strlen(s), s, 1);
		free(free_s);
	}
	s = flags_oux_acc2(par, type, s, num);
	return (s);
}

static char	*flags_oux_acc(t_plist *par, char type, char *s, int num)
{
	char *free_s;

	free_s = s;
	if (par->if_acc == 1)
		s = flags_oux_acc1(par, type, s, num);
	else if (ft_while_not_n(par->flag, '#') >= 0 && type == 'o' && num != 0)
	{
		s = ft_strcjoin(s, '0', -1);
		free(free_s);
	}
	else if (ft_while_not_n(par->flag, '#') >= 0 && num != 0 &&
		(ft_while_not_n(par->flag, '0') < 0 ||
		ft_while_not_n(par->flag, '-') >= 0 ||
		(int)ft_strlen(s) > par->wide) && (type == 'x' || type == 'X'))
	{
		s = ft_strjoin("0x", s);
		free(free_s);
	}
	return (s);
}

static char	*do_x_up(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'f') || s[i] == 'x')
			s[i] = s[i] - 32;
		i++;
	}
	return (s);
}

char		*flags_oux(t_plist *par, char type, char *s, int num)
{
	char	*free_s;

	s = flags_oux_acc(par, type, s, num);
	free_s = s;
	if (par->wide > (int)ft_strlen(s))
	{
		if (ft_while_not_n(par->flag, '-') >= 0)
			s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, -1);
		else if (ft_while_not_n(par->flag, '0') >= 0)
		{
			s = ft_n_and_s('0', par->wide - ft_strlen(s), s, 1);
			if (ft_while_not_n(par->flag, '#') >= 0 &&
				(type == 'x' || type == 'X') && num != 0)
				s[1] = 'x';
		}
		else
			s = ft_n_and_s(' ', par->wide - ft_strlen(s), s, 1);
		free(free_s);
	}
	if (type == 'X')
		return (do_x_up(s));
	return (s);
}
