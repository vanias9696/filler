/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:34:34 by ismus             #+#    #+#             */
/*   Updated: 2018/04/05 16:34:35 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	break_up(t_map *map, int x)
{
	int k;
	int n;
	int ch;

	k = map->where_x == -1 ? x - map->fig_x + 1 : x;
	while (k >= x - map->fig_x + 1 && k <= x)
	{
		n = 4 - map->fig_n;
		while (n < map->map_n + map->fig_n)
		{
			ch = check(map, k, n);
			if (ch == 1)
				break ;
			n++;
		}
		if (ch == 1)
			break ;
		k = k + map->where_x;
	}
	if (ch == 1)
		output_pr(k - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

int			joint_symb(t_map *map)
{
	int nx;
	int x;
	int a;

	nx = map->where_x == -1 ? 1 : map->map_x;
	x = nx;
	while (ft_while_not_n(map->map[nx], map->nsym) < 2)
		nx = nx - map->where_x;
	while (ft_while_not_n(map->map[x], map->sym + 32) < 2 &&
		ft_while_not_n(map->map[x], map->sym) < 2)
		x = x - map->where_x;
	a = map->where_x == -1 ? x - nx : nx - x;
	if (a > 0 && a <= map->fig_x + 1)
		return (break_up(map, x));
	return (0);
}
