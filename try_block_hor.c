/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_block_hor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:33:34 by ismus             #+#    #+#             */
/*   Updated: 2018/04/12 11:33:35 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		b_l_up(t_map *map, int i)
{
	int n;
	int ch;

	while (i < map->map_x)
	{
		n = 4 - map->fig_n;
		while (n < map->adrn + 2)
		{
			ch = check(map, i, n);
			if (ch == 1)
				break ;
			n++;
		}
		if (ch == 1)
			break ;
		i++;
	}
	if (ch == 1)
		output_pr(i - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

int		b_r_up(t_map *map, int i, int n, int k)
{
	int ch;

	while (i < map->map_x)
	{
		n = ft_rev_while_not_n(map->map[i], map->sym + 32);
		k = ft_rev_while_not_n(map->map[i], map->sym);
		if (k < 0)
			k = n;
		else if (n > 0)
			k = k < n ? n - 1 : k - 1;
		n = map->map_n + 4;
		while (n > k)
		{
			ch = check(map, i, n);
			if (ch == 1)
				break ;
			n--;
		}
		if (ch == 1)
			break ;
		i++;
	}
	if (ch == 1)
		output_pr(i - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

int		b_l_down(t_map *map, int i)
{
	int n;
	int ch;

	while (i > 1 - map->fig_x)
	{
		n = 4 - map->fig_n;
		while (n < map->adrn + 2)
		{
			ch = check(map, i, n);
			if (ch == 1)
				break ;
			n++;
		}
		if (ch == 1)
			break ;
		i--;
	}
	if (ch == 1)
		output_pr(i - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

int		b_r_down(t_map *map, int i, int n, int k)
{
	int	ch;

	while (i > 1)
	{
		n = ft_rev_while_not_n(map->map[i], map->sym + 32);
		k = ft_rev_while_not_n(map->map[i], map->sym);
		if (k < 0)
			k = n;
		else if (n > 0)
			k = k < n ? k - 1 : n - 1;
		n = map->map_n + 4;
		while (n > k)
		{
			ch = check(map, i, n);
			if (ch == 1)
				break ;
			n--;
		}
		if (ch == 1)
			break ;
		i--;
	}
	if (ch == 1)
		output_pr(i - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}
