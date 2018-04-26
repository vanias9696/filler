/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:59:08 by ismus             #+#    #+#             */
/*   Updated: 2018/04/24 14:59:09 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_wide(t_map *map, int i, int du, int n)
{
	int x;
	int y;
	int ch;

	x = du > 0 ? i - map->fig_x : i;
	ch = 0;
	while (x >= i - map->fig_x && x <= i && ch != 1)
	{
		y = n;
		while (y >= 3 && y <= map->map_n + 3 && ch != 1)
		{
			ch = check(map, x, y) == 1;
			if (ch == 1)
				break ;
			y = n == 3 - map->fig_n ? ++y : --y;
		}
		if (ch == 1)
			break ;
		x = (du > 0 ? ++x : --x);
	}
	if (ch == 1)
		return (output_pr(x - 1, y - 4, 1, map));
	return (0);
}

int		last_check(t_map *map, int x, int y)
{
	int where_x;
	int ch;
	int n;

	where_x = x == map->map_x ? -1 : 1;
	while (x >= 2 - map->fig_x && x <= map->map_x)
	{
		n = y;
		while (n <= map->map_n + 3 && n >= 5 - map->fig_n)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break ;
			n = y == 4 ? n + 1 : n - 1;
		}
		if (ch == 1)
			break ;
		x = x + where_x;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1, map);
	else
		output_pr(0, 0, 1, map);
	return (ch == 1 ? 1 : 0);
}

void	find_near(t_map *map)
{
	int nx;

	nx = map->where_x == -1 ? 1 : map->map_x;
	if (map->nadrn < map->adrn)
		while (ft_rev_while_not_n(map->map[nx], map->nsym) < 2)
			nx = nx - map->where_x;
	else
		while (ft_while_not_n(map->map[nx], map->nsym) < 2)
			nx = nx - map->where_x;
	map->last_x = nx;
	if (map->nadrn < map->adrn)
		map->last_n = ft_rev_while_not_n(map->map[nx], map->nsym);
	else
		map->last_n = ft_while_not_n(map->map[nx], map->nsym);
}

int		wide_block(t_map *map, int tu, int td, int i)
{
	int k;

	while (ft_while_not_n(map->map[i], map->nsym) < 0 &&
		ft_while_not_n(map->map[i++], map->nsym + 32) < 0)
		td++;
	k = map->map_x;
	while (ft_while_not_n(map->map[k], map->nsym) < 0 &&
		ft_while_not_n(map->map[k--], map->nsym + 32) < 0)
		tu++;
	i = td > tu ? i : k;
	while (ft_while_not_n(map->map[i], map->sym) < 0)
	{
		i = td > tu ? --i : ++i;
		if (i < 1 || i > map->map_x)
			break ;
	}
	if (i < 1 || i > map->map_x)
		return (0);
	k = map->nadrn > map->adrn ? map->map_n + 3 : 3 - map->fig_n;
	if ((k == map->map_n + 3 && map->is_block_r == 1) ||
		(k == 3 - map->fig_n && map->is_block_l == 1))
		return (0);
	return (check_wide(map, i, td - tu, k) == 1 ? 1 : 0);
}
