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

static int	have_sym(int i, t_map *map)
{
	int x;
	int n;

	x = map->last_x - i;
	while (x <= map->last_x + i)
	{
		n = map->last_n - i;
		while (n <= map->last_n + i)
		{
			if (x <= map->map_x && x > 0 && n > 3 && n < map->map_n + 4 &&
				(map->map[x][n] == map->sym || map->map[x][n] == map->sym + 32))
				break ;
			n++;
		}
		if (n != map->last_n + i + 1)
			break ;
		x++;
	}
	map->block_x = x;
	map->block_n = n;
	return (x <= map->last_x + i ? 1 : 0);
}

static int	case_a(t_map *map)
{
	int x;
	int n;
	int ch;

	x = map->block_x - map->fig_x - 1;
	while (x <= map->block_x)
	{
		n = map->block_n;
		while (n >= map->block_n - map->fig_n - 1)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break ;
			n--;
		}
		if (ch == 1)
			break ;
		x++;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

static int	case_b(t_map *map)
{
	int x;
	int n;
	int ch;

	x = map->block_x - map->fig_x - 1;
	while (x <= map->block_x)
	{
		n = map->block_n - map->fig_n - 1;
		while (n <= map->block_n)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break ;
			else
				n++;
		}
		if (ch == 1)
			break ;
		else
			x++;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

static int	case_c(t_map *map)
{
	int x;
	int n;
	int ch;

	x = map->block_x + 2;
	while (x >= map->block_x - map->fig_x + 1)
	{
		n = map->block_n + 2;
		while (n >= map->block_n - map->fig_n + 1)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break ;
			n--;
		}
		if (ch == 1)
			break ;
		x--;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

static int	case_d(t_map *map)
{
	int x;
	int n;
	int ch;

	x = map->block_x + 2;
	while (x >= map->block_x - map->fig_x + 1)
	{
		n = map->block_n - map->fig_n - 1;
		while (n <= map->block_n)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break ;
			n++;
		}
		if (ch == 1)
			break ;
		x--;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1, map);
	return (ch == 1 ? 1 : 0);
}

int			find_wall(t_map *map, int n)
{
	int i;

	i = 1;
	while (i <= map->map_x)
	{
		if (map->map[i][n] == map->sym || map->map[i][n] == map->sym + 32)
		{
			map->wall_x = n == 4 ? -i : i;
			return (1);
		}
		i++;
	}
	return (0);
}

int			where_i(t_map *map)
{
	if (map->nadrX < map->adrX && map->block_x <= map->last_x)
		return (1);
	else if (map->nadrX > map->adrX && map->block_x >= map->last_x)
		return (1);
	return (0);
}

int			try_block_up(t_map *map)
{
	int i;

	i = 1;
	while (have_sym(i, map) == 0 && i < map->map_n)
		i++;
	if (i == map->map_n)
		return (0);
	if (where_i(map) == 1 && wide_block(map) == 1)
		return (1);
	if (map->block_x > map->last_x && map->block_n < map->last_n)
		i = case_a(map);
	else if (map->block_x > map->last_x)
		i = case_b(map);
	else if (map->block_n < map->last_n)
		i = case_c(map);
	else
		i = case_d(map);
	return (i == 0 ? 0 : 1);
}

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
