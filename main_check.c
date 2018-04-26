/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:16:47 by ismus             #+#    #+#             */
/*   Updated: 2018/04/24 16:16:48 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	block_else_h(t_map *map, int i)
{
	while (ft_while_not_n(map->map[i], map->nsym) < 2)
		i++;
	if (ft_rwhile_nbl(map->map[i], map->sym, map->nsym, '\0') < 0 &&
		ft_rwhile_nbl(map->map[i], map->sym + 32, map->nsym, '\0') < 0)
	{
		while (i > 0 &&
			ft_rwhile_nbl(map->map[i], map->sym, map->nsym, '\0') < 0 &&
			ft_rwhile_nbl(map->map[i], map->sym + 32, map->nsym, '\0') < 0)
			i--;
		i = i - map->fig_x + 2;
		if (map->adrn > map->nadrn)
			return (b_l_down(map, i));
		else
			return (b_r_down(map, i, 0, 0));
	}
	else
	{
		while (i <= map->map_x &&
			ft_rwhile_nbl(map->map[i], map->sym, map->nsym, '\0') > 0 &&
			ft_rwhile_nbl(map->map[i], map->sym + 32, map->nsym, '\0') > 0)
			i++;
		i--;
	}
	return (map->adrn > map->nadrn ? b_l_up(map, i) : b_r_up(map, i, 0, 0));
}

static int	block_else(t_map *map, int i)
{
	if (map->adrx > map->nadrx)
	{
		while (ft_while_not_n(map->map[i], map->nsym) < 2)
			i--;
		if (ft_while_not_n(map->map[i], map->sym) < 0 &&
			ft_while_not_n(map->map[i], map->sym + 32) < 0)
		{
			while (i >= 1 && ft_while_not_n(map->map[i], map->sym) < 0 &&
				ft_while_not_n(map->map[i], map->sym + 32) < 0)
				i--;
			if (map->adrn > map->nadrn)
				return (b_l_down(map, i));
			else
				return (b_r_down(map, i, 0, 0));
		}
		i = i - map->fig_x;
		return (map->adrn > map->nadrn ? b_l_up(map, i) : b_r_up(map, i, 0, 0));
	}
	else
		return (block_else_h(map, i));
}

static int	third_is_overtook(t_map *map)
{
	int i;

	i = (map->adrx > map->nadrx ? 1 : map->map_x);
	while (ft_while_not_n(map->map[i], map->sym) < 2 &&
		ft_while_not_n(map->map[i], map->sym + 32) < 2)
		i = map->adrx > map->nadrx ? ++i : --i;
	i = map->adrx > map->nadrx ? --i : ++i;
	if (map->adrx > map->nadrx && i > map->map_x / 5)
		return (0);
	if (map->adrx <= map->nadrx && map->map_x - i >= map->map_x / 5)
		return (0);
	i = map->adrx > map->nadrx ? map->map_x : 1;
	return (block_else(map, i));
}

int			is_overtook(t_map *map)
{
	int i;

	if (map->adrx < map->nadrx && map->is_block_r == 1 && map->is_block_l != 1)
	{
		i = map->map_x + 1;
		while (--i > 0 && ft_while_nbl(map->map[i], map->sym, map->nsym) < 0)
			if (ft_while_nbl(map->map[i], map->sym, map->nsym) > 3)
				break ;
		if (i > 0 && check_wide(map, i, -1, 3 - map->fig_n) == 1)
			return (1);
	}
	i = map->adrx < map->nadrx ? 1 : map->map_x;
	while (i > 0 && i <= map->map_x &&
		ft_rwhile_nbl(map->map[i], map->nsym, map->sym, map->sym + 32) < 0)
		i = map->adrx < map->nadrx ? ++i : --i;
	if (map->adrx < map->nadrx && i > 0 && i < map->map_x &&
		check_fig(map, 0) == 1 &&
		ft_rwhile_nbl(map->map[i - 1], map->nsym, map->sym, map->sym + 32) < 0
		&& ft_while_not_n(map->map[i - 1], map->nsym) > 0 &&
		b_r_down(map, i - 1, 0, 0) == 1)
		return (1);
	if (check_fig(map, 0) == 1 && i > 0 && i < map->map_x &&
		b_r_up(map, i, 0, 0) == 1)
		return (1);
	return (third_is_overtook(map));
}
