/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_block_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:51:50 by ismus             #+#    #+#             */
/*   Updated: 2018/04/24 14:51:50 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int			try_block_up(t_map *map)
{
	int i;

	i = 1;
	while (have_sym(i, map) == 0 && i < map->map_n)
		i++;
	if (i == map->map_n)
		return (0);
	if (((map->nadrx < map->adrx && map->block_x <= map->last_x) ||
		(map->nadrx > map->adrx && map->block_x >= map->last_x)) &&
		wide_block(map, 0, 0, 1) == 1)
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
