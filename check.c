/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:48:01 by ismus             #+#    #+#             */
/*   Updated: 2018/04/24 14:48:02 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_dot(int x, t_map *map)
{
	int n;

	n = 0;
	while (x < map->fig_x)
	{
		while (n < map->fig_n)
		{
			if (map->fig[x][n] != '.')
				return (0);
			n++;
		}
		x++;
	}
	return (1);
}

static int	cycle_check(t_map *map, int i, int j, int x)
{
	int n;
	int cross;

	cross = 0;
	n = 0;
	while (n < map->fig_n && cross <= 1)
	{
		if (map->fig[x][n] == '.')
			n = n + 0;
		else if (j + n > map->map_n + 3 || j + n < 4 || i + x < 1
			|| i + x > map->map_x)
			return (-1);
		else if (map->map[i + x][j + n] != '.' &&
			map->map[i + x][j + n] != map->sym + 32
			&& map->map[i + x][j + n] != map->sym)
			return (-1);
		else if (map->fig[x][n] == '*' &&
			(map->map[i + x][j + n] == map->sym
			|| map->map[i + x][j + n] == map->sym + 32))
			cross++;
		n++;
	}
	if (n < map->fig_n && map->map[i + x][j + n] == '\0')
		return (-1);
	return (cross);
}

int			check_fig(t_map *map, int m)
{
	int i;
	int n;

	n = -1;
	while (++n < map->fig_n)
	{
		i = -1;
		while (++i < map->fig_x)
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

int			check(t_map *map, int i, int j)
{
	int x;
	int n;
	int cross;

	x = 0;
	cross = 0;
	while (x < map->fig_x && cross <= 1)
	{
		n = cycle_check(map, i, j, x);
		if (n < 0)
			return (0);
		cross = cross + n;
		x++;
	}
	if (x < map->fig_x && map->map[i + x] == 0)
	{
		if (check_dot(x, map) == 1 && cross == 1)
			return (1);
		return (0);
	}
	return (cross != 1 ? 0 : 1);
}
