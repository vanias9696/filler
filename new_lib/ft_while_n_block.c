/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_n_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:24:54 by ismus             #+#    #+#             */
/*   Updated: 2018/04/17 14:24:54 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_while_nbl(char *str, char n, char c)
{
	int	i;

	i = 0;
	while (str[i] != n && str[i] && str[i] != c)
		i++;
	if (!(str[i]) || str[i] == c)
		return (-1);
	return (i);
}

int		ft_rwhile_nbl(char *str, char n, char c, char m)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] != n && str[i] != '\0' && str[i] != c && str[i] != m)
		i--;
	if (!(str[i]) || str[i] == c || str[i] == m)
		return (-1);
	return (i);
}
