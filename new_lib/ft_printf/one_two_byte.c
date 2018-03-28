/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_two_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:42:49 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 16:42:50 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	two_byte_print2(unsigned int a0, unsigned int a1, t_plist *par)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 2, '0');
		ft_putstr(free_s);
		ft_putchar(a0);
		ft_putchar(a1);
	}
	else
	{
		free_s = ft_by_n(par->wide - 2, ' ');
		ft_putstr(free_s);
		ft_putchar(a0);
		ft_putchar(a1);
	}
	free(free_s);
}

static int	two_byte_print(unsigned int a0, unsigned int a1, t_plist *par)
{
	char	*free_s;

	if (par->wide > 2)
	{
		if (ft_while_not_n(par->flag, '-') >= 0)
		{
			ft_putchar(a0);
			ft_putchar(a1);
			free_s = ft_by_n(par->wide - 2, ' ');
			ft_putstr(free_s);
			free(free_s);
		}
		else
			two_byte_print2(a0, a1, par);
		return (par->wide);
	}
	ft_putchar(a0);
	ft_putchar(a1);
	return (2);
}

int			two_byte(char *s, t_plist *par)
{
	unsigned int	a0;
	unsigned int	a1;
	char			*free_s;

	free_s = s;
	s = ft_n_and_s('0', 16 - ft_strlen(s), s, 1);
	free(free_s);
	a0 = s[6] - 48 + (s[5] - 48) * 10;
	a0 = a0 * 10 + (s[7] - 48);
	a0 = a0 * 10 + (s[8] - 48);
	a0 = a0 * 10 + (s[9] - 48);
	a0 = a0 + 11000000;
	a1 = s[11] - 48 + (s[10] - 48) * 10;
	a1 = a1 * 10 + (s[12] - 48);
	a1 = a1 * 10 + (s[13] - 48);
	a1 = a1 * 10 + (s[14] - 48);
	a1 = a1 * 10 + (s[15] - 48);
	a1 = a1 + 10000000;
	a0 = two_to_ten(a0);
	a1 = two_to_ten(a1);
	free(s);
	return (two_byte_print(a0, a1, par));
}

static void	one_byte_print2(unsigned int i, t_plist *par)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 1, '0');
		ft_putstr(free_s);
		ft_putchar(i);
	}
	else
	{
		free_s = ft_by_n(par->wide - 1, ' ');
		ft_putstr(free_s);
		ft_putchar(i);
	}
	free(free_s);
}

int			one_byte(unsigned int i, t_plist *par)
{
	char	*free_s;

	if (par->wide > 1)
	{
		if (ft_while_not_n(par->flag, '-') >= 0)
		{
			ft_putchar(i);
			free_s = ft_by_n(par->wide - 1, ' ');
			ft_putstr(free_s);
			free(free_s);
		}
		else
			one_byte_print2(i, par);
		return (par->wide);
	}
	ft_putchar(i);
	return (1);
}
