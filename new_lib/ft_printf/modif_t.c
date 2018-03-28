/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:11:34 by ismus             #+#    #+#             */
/*   Updated: 2018/03/16 17:11:34 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		modif_t(t_plist *par, va_list arg, char type)
{
	intmax_t	i;
	char		*s;

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
