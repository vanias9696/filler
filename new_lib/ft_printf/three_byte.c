/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:38:13 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 16:38:13 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	a0_three_byte(char *s, unsigned int a0)
{
	a0 = s[1] - 48 + (s[0] - 48) * 10;
	a0 = a0 * 10 + (s[2] - 48);
	a0 = a0 * 10 + (s[3] - 48);
	a0 = a0 + 11100000;
	a0 = two_to_ten(a0);
	return (a0);
}

static unsigned int	a1_three_byte(char *s, unsigned int a1)
{
	a1 = s[5] - 48 + (s[4] - 48) * 10;
	a1 = a1 * 10 + (s[6] - 48);
	a1 = a1 * 10 + (s[7] - 48);
	a1 = a1 * 10 + (s[8] - 48);
	a1 = a1 * 10 + (s[9] - 48);
	a1 = a1 + 10000000;
	a1 = two_to_ten(a1);
	return (a1);
}

static void			pr_nbr(t_byte *num)
{
	ft_putchar(num->a0);
	ft_putchar(num->a1);
	ft_putchar(num->a2);
}

static int			three_byte_print(t_byte *num, t_plist *par)
{
	char	*free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		pr_nbr(num);
		free_s = ft_by_n(par->wide - 3, ' ');
		ft_putstr(free_s);
		free(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 3, '0');
		ft_putstr(free_s);
		free(free_s);
		pr_nbr(num);
	}
	else
	{
		free_s = ft_by_n(par->wide - 3, ' ');
		ft_putstr(free_s);
		free(free_s);
		pr_nbr(num);
	}
	free(num);
	return (par->wide);
}

int					three_byte(char *s, t_plist *par)
{
	t_byte	*num;
	char	*free_s;

	num = (t_byte *)malloc(sizeof(t_byte));
	if (ft_strlen(s) < 16)
	{
		free_s = s;
		s = ft_n_and_s('0', 16 - ft_strlen(s), s, 1);
		free(free_s);
	}
	num->a2 = s[11] - 48 + (s[10] - 48) * 10;
	num->a2 = num->a2 * 10 + (s[12] - 48);
	num->a2 = num->a2 * 10 + (s[13] - 48);
	num->a2 = num->a2 * 10 + (s[14] - 48);
	num->a2 = num->a2 * 10 + (s[15] - 48);
	num->a2 = num->a2 + 10000000;
	num->a0 = a0_three_byte(s, num->a0);
	num->a1 = a1_three_byte(s, num->a1);
	num->a2 = two_to_ten(num->a2);
	if (par->wide > 3)
		return (three_byte_print(num, par));
	pr_nbr(num);
	free(num);
	free(s);
	return (3);
}
