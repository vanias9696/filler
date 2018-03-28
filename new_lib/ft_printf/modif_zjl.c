/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:33:42 by ismus             #+#    #+#             */
/*   Updated: 2018/03/04 15:33:43 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		modif_z(t_plist *par, va_list arg, char type)
{
	size_t	i;
	char	*s;

	i = va_arg(arg, size_t);
	if (type == 'x' || type == 'X')
		s = ft_utoa_base(i, 16);
	else if (type == 'o')
		s = ft_utoa_base(i, 8);
	else if (type == 'u')
		s = ft_utoa_base(i, 10);
	else
		s = ft_itoa_base(i, 10);
	if (type != 'i' && type != 'd')
		s = flags_oux(par, type, s, i);
	else
		s = flags_id(par, s);
	i = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (i);
}

int		modif_j(t_plist *par, va_list arg, char type)
{
	uintmax_t	i;
	intmax_t	in;
	char		*s;

	if (type == 'i' || type == 'd')
		in = va_arg(arg, intmax_t);
	else
		i = va_arg(arg, uintmax_t);
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

int		modif_ll(t_plist *par, va_list arg, char type)
{
	unsigned long long int	i;
	long long int			in;
	char					*s;

	if (type == 'i' || type == 'd')
		in = va_arg(arg, long long int);
	else
		i = va_arg(arg, unsigned long long int);
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

int		modif_lc(t_plist *par, va_list arg)
{
	unsigned int	c;

	c = va_arg(arg, unsigned int);
	if (MB_CUR_MAX == 4)
		return (unicode(c, par));
	return (one_byte(c, par));
}

int		modif_l(t_plist *par, va_list arg, char type)
{
	unsigned long int	i;
	long int			in;
	char				*s;

	if (type == 'i' || type == 'd')
		in = va_arg(arg, long int);
	else
		i = va_arg(arg, unsigned long int);
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
