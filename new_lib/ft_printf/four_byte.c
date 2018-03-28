/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:03:31 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 16:03:32 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			a2_four_byte(char *s, t_byte *num)
{
	num->a1 = s[4] - 48 + (s[3] - 48) * 10;
	num->a1 = num->a1 * 10 + (s[5] - 48);
	num->a1 = num->a1 * 10 + (s[6] - 48);
	num->a1 = num->a1 * 10 + (s[7] - 48);
	num->a1 = num->a1 * 10 + (s[8] - 48);
	num->a1 = num->a1 + 10000000;
	num->a2 = s[10] - 48 + (s[9] - 48) * 10;
	num->a2 = num->a2 * 10 + (s[11] - 48);
	num->a2 = num->a2 * 10 + (s[12] - 48);
	num->a2 = num->a2 * 10 + (s[13] - 48);
	num->a2 = num->a2 * 10 + (s[14] - 48);
	num->a2 = num->a2 + 10000000;
}

static unsigned int	a3_four_byte(char *s, unsigned int a3)
{
	a3 = s[16] - 48 + (s[15] - 48) * 10;
	a3 = a3 * 10 + (s[17] - 48);
	a3 = a3 * 10 + (s[18] - 48);
	a3 = a3 * 10 + (s[19] - 48);
	a3 = a3 * 10 + (s[20] - 48);
	a3 = a3 + 10000000;
	a3 = two_to_ten(a3);
	return (a3);
}

static void			four_byte_print(t_byte *num)
{
	ft_putchar(num->a0);
	ft_putchar(num->a1);
	ft_putchar(num->a2);
	ft_putchar(num->a3);
}

static int			four_print(t_plist *par, t_byte *num)
{
	char *free_s;

	if (ft_while_not_n(par->flag, '-') >= 0)
	{
		free_s = ft_by_n(par->wide - 4, ' ');
		four_byte_print(num);
		ft_putstr(free_s);
	}
	else if (ft_while_not_n(par->flag, '0') >= 0)
	{
		free_s = ft_by_n(par->wide - 4, '0');
		ft_putstr(free_s);
		four_byte_print(num);
	}
	else
	{
		free_s = ft_by_n(par->wide - 4, ' ');
		ft_putstr(free_s);
		four_byte_print(num);
	}
	free(free_s);
	return (par->wide);
}

int					four_byte(char *s, t_plist *par)
{
	t_byte	*num;
	char	*free_s;

	num = (t_byte *)malloc(sizeof(t_byte));
	if (ft_strlen(s) < 21)
	{
		free_s = s;
		s = ft_n_and_s('0', 21 - ft_strlen(s), s, 1);
		free(free_s);
	}
	num->a0 = s[1] - 48 + (s[0] - 48) * 10;
	num->a0 = num->a0 * 10 + (s[2] - 48);
	num->a0 = num->a0 + 11110000;
	num->a0 = two_to_ten(num->a0);
	a2_four_byte(s, num);
	num->a1 = two_to_ten(num->a1);
	num->a2 = two_to_ten(num->a2);
	num->a3 = a3_four_byte(s, num->a3);
	free(s);
	if (par->wide > 4)
		return (four_print(par, num));
	four_byte_print(num);
	return (4);
}
