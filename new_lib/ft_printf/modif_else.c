/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:38:03 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 15:38:03 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		for_h(t_plist *par, char type, char *s, int in)
{
	int i;

	if (type == 'o' || type == 'x' || type == 'X' || type == 'u')
		s = flags_oux(par, type, s, in);
	else if (in < 0)
		s = flags_mid(par, s);
	else
		s = flags_id(par, s);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int				modif_h(t_plist *par, va_list arg, char type)
{
	unsigned short int	i;
	short int			in;
	char				*s;
	int					a;

	a = va_arg(arg, int);
	in = 0;
	if (type == 'i' || type == 'd')
		in = (short int)a;
	else
		i = (unsigned short int)a;
	if (type == 'x' || type == 'X')
		s = ft_utoa_base(i, 16);
	else if (type == 'o')
		s = ft_utoa_base(i, 8);
	else if (type == 'u')
		s = ft_utoa_base(i, 10);
	else
		s = ft_itoa_base(in, 10);
	if (type == 'i' || type == 'd')
		return (for_h(par, type, s, in));
	return (for_h(par, type, s, i));
}

int				modif_hh(t_plist *par, va_list arg, char type)
{
	unsigned char	i;
	signed char		in;
	char			*s;
	int				a;

	a = va_arg(arg, int);
	in = 0;
	if (type == 'i' || type == 'd')
		in = (signed char)a;
	else
		i = (unsigned char)a;
	if (type == 'x' || type == 'X')
		s = ft_utoa_base(i, 16);
	else if (type == 'o')
		s = ft_utoa_base(i, 8);
	else if (type == 'u')
		s = ft_utoa_base(i, 10);
	else
		s = ft_itoa_base(in, 10);
	if (type == 'i' || type == 'd')
		return (for_h(par, type, s, in));
	return (for_h(par, type, s, i));
}

int				modif_idoux(t_plist *par, va_list arg, char type)
{
	unsigned int	i;
	int				in;
	char			*s;

	if (type == 'i' || type == 'd')
		in = va_arg(arg, int);
	else
		i = va_arg(arg, unsigned int);
	if (type == 'x' || type == 'X')
		s = ft_utoa_base(i, 16);
	else if (type == 'o')
		s = ft_utoa_base(i, 8);
	else if (type == 'u')
		s = ft_utoa_base(i, 10);
	else
		s = ft_itoa_base(in, 10);
	if (type != 'i' && type != 'd')
		s = flags_oux(par, type, s, i);
	else
		s = flags_id(par, s);
	ft_putstr(s);
	i = ft_strlen(s);
	free(s);
	return (i);
}
