/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_and_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:27:35 by ismus             #+#    #+#             */
/*   Updated: 2018/03/06 18:27:36 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_n_and_s(char symb, int num, char *str, int first)
{
	char *n_str;
	char *free_s;

	free_s = ft_by_n(num, symb);
	if (first >= 0)
		n_str = ft_strjoin(free_s, str);
	else
		n_str = ft_strjoin(str, free_s);
	free(free_s);
	return (n_str);
}
