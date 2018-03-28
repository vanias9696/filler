/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:34:50 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 15:34:51 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	two_to_ten(unsigned int k)
{
	unsigned int	i;
	int				num;

	i = 0;
	num = 1;
	while (k != 0)
	{
		i = i + (k % 10) * num;
		k = k / 10;
		num = num * 2;
	}
	return (i);
}

int				unicode(unsigned int i, t_plist *par)
{
	char	*s;
	int		a;

	a = 0;
	if (i < 128)
		return (one_byte(i, par));
	else if (i > 127 && i < 2048)
	{
		s = ft_utoa_base(i, 2);
		a = two_byte(s, par);
	}
	else if (i > 2047 && i < 65536)
	{
		s = ft_utoa_base(i, 2);
		a = three_byte(s, par);
	}
	else
	{
		s = ft_utoa_base(i, 2);
		a = four_byte(s, par);
	}
	return (a);
}

void			str_unicode(unsigned int *s)
{
	int		i;
	t_plist	*null;

	null = (t_plist *)malloc(sizeof(t_plist));
	null->flag = ft_strnew(1);
	null->spec = ft_strnew(1);
	null->if_acc = 0;
	null->wide = 0;
	i = 0;
	while (s[i])
	{
		unicode(s[i], null);
		i++;
	}
	free(null->flag);
	free(null->spec);
	free(null);
}
