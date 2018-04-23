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
		while (n < map->adrN + 2)
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

static int	b_r_up(t_map *map, int i)
{
	int n;
	int ch;
	int k;

	while (i < map->map_x)
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
		i++;
	}
	if (ch == 1)
		output_pr(i - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

static int	b_l_down(t_map *map, int i)
{
	int n;
	int ch;

	while (i > 1 - map->fig_x)
	{
		n = 4 - map->fig_n;
		while (n < map->adrN + 2)
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

static int	b_r_down(t_map *map, int i)
{
	int n;
	int ch;
	int k;

	printf("lrg\n");
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

static int	block_else(t_map *map, int i)
{
	//printf("block else\n");
	if (map->adrX > map->nadrX)
	{
		while (ft_while_not_n(map->map[i], map->nsym) < 2)
			i--;
		if (ft_while_not_n(map->map[i], map->sym) < 0 &&
			ft_while_not_n(map->map[i], map->sym + 32) < 0)
		{
			while (i >= 1 && ft_while_not_n(map->map[i], map->sym) < 0 &&
				ft_while_not_n(map->map[i], map->sym + 32) < 0)
				i--;
			return (map->adrN > map->nadrN ? b_l_down(map, i) : b_r_down(map, i));
		}
		i = i - map->fig_x;
		return (map->adrN > map->nadrN ? b_l_up(map, i) : b_r_up(map, i));
	}
	else
	{
		while (ft_while_not_n(map->map[i], map->nsym) < 2)
			i++;
		if (ft_rev_while_n_block(map->map[i], map->sym, map->nsym, '\0') < 0 &&
			ft_rev_while_n_block(map->map[i], map->sym + 32, map->nsym, '\0') < 0)
		{
			while (i > 0 && ft_rev_while_n_block(map->map[i], map->sym, map->nsym, '\0') < 0 &&
				ft_rev_while_n_block(map->map[i], map->sym + 32, map->nsym, '\0') < 0)
				i--;
			i = i - map->fig_x + 2;
			return (map->adrN > map->nadrN ? b_l_down(map, i) : b_r_down(map, i));
		}
		else
		{
			while (i <= map->map_x && ft_rev_while_n_block(map->map[i], map->sym, map->nsym, '\0') > 0 &&
				ft_rev_while_n_block(map->map[i], map->sym + 32, map->nsym, '\0') > 0)
				i++;
			i--;
		}
		return (map->adrN > map->nadrN ? b_l_up(map, i) : b_r_up(map, i));
	}
}

int			check_fig(t_map *map)
{
	int i;
	int n;
	int m;

	n = -1;
	m = 0;
	while(++n < map->fig_n)
	{
		i = -1;
		while(++i < map->fig_x)
			if (map->fig[i][n] == '*')
			{
				m++;
				break ;
			}
	}
	i = 0;
	n = 0;
	while (i < map->fig_x)
	{
		if (ft_while_not_n(map->fig[i], '*') > 0)
			n++;
		i++;
	}
	if (n > m)
		return (0);
	return (1);

}

int			is_overtook(t_map *map)
{
	int i;

	if (map->adrX < map->nadrX && map->is_block_r == 1 && map->is_block_l != 1)
	{
		i = map->map_x;
		while(i > 0 && ft_while_n_block(map->map[i], map->sym, map->nsym) < 0)
		{
			if (ft_while_n_block(map->map[i], map->sym, map->nsym) > 3)
				break ;
			i--;
		}
		if (i > 0 && check_wide(map, i, -1, 3 - map->fig_n) == 1)
			return (1);
	}
	i = map->adrX < map->nadrX ? 1 : map->map_x;
	while(i > 0 && i <= map->map_x &&
		ft_rev_while_n_block(map->map[i], map->nsym, map->sym, map->sym + 32) < 0)
		i = map->adrX < map->nadrX ? ++i : --i;
	if (map->adrX < map->nadrX && i > 0 && i < map->map_x && check_fig(map) == 1 &&
		ft_rev_while_n_block(map->map[i - 1], map->nsym, map->sym, map->sym + 32) < 0 &&
		ft_while_not_n(map->map[i - 1], map->nsym) > 0 && b_r_down(map, i - 1) == 1)
		return (1);
	/*
	if (map->adrX < map->nadrX)
	{
		k = map->fig_x - 1;
		while (ft_while_not_n(map->fig[k], '*') < 0)
				k--;
		i = i - k - 1;
	}
	*/
	//--i;
	if (check_fig(map) == 1 && i > 0 && i < map->map_x && b_r_up(map, i) == 1)
		//check_wide(map, i, -1, map->map_n + 3) == 1)
		return (1);
	i = (map->adrX > map->nadrX ? 1 : map->map_x);
	while (ft_while_not_n(map->map[i], map->sym) < 2 &&
		ft_while_not_n(map->map[i], map->sym + 32) < 2)
		i = map->adrX > map->nadrX ? ++i : --i;
	i = map->adrX > map->nadrX ? --i : ++i;
	if (map->adrX > map->nadrX && i > map->map_x / 5)
		return (0);
	if (map->adrX <= map->nadrX && map->map_x - i >= map->map_x / 5)
		return (0);
	i = map->adrX > map->nadrX ? map->map_x : 1;
	return (block_else(map, i));
}
