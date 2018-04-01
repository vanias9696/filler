/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:35:25 by ismus             #+#    #+#             */
/*   Updated: 2018/04/01 16:35:25 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check(t_map *map, int i, int j)
{
	int x;
	int n;
	int cross;

	x = 0;
	cross = 0;
	while (map->map[i + x] != 0 && x < map->fig_x)
	{
		n = 0;
		while (map->map[i + x][j + n] != '\0' && n < map->fig_n)
		{
			if (map->fig[x][n] != '.' && map->map[i + x][j + n] == map->nsym)
				return (0);
			if (map->fig[x][n] == '*' && map->map[i + x][j + n] == map->sym)
				cross++;
			n++;
		}
		if (n < map->fig_n && map->map[i + x][j + n] == '\0')
			return (0);
		x++;
	}
	if (x < map->fig_x && map->map[i + x] == 0)
		return (0);
	return (cross != 1 ? 0 : 1);
}

static void	chek_subst(t_map *map, int where_x, int where_n)
{
	int i;
	int j;
	int norm;

	if (where_x < 0)
		i = 1 - map->fig_x;
	else
		i = 0;
	norm = 0;
	while ((norm == 0) && i <= 0 && i > -1 * map->fig_x)
	{
		j = (where_n < 0 ? 1 - map->fig_n : 0);
		while (norm == 0 && j <= 0 && j > -1 * map->fig_n)
		{
			norm = check(map, map->adrX + i, map->adrN + j);
			if (norm == 0)
				j = j - where_n;
		}
		if (norm == 0)
			i = i - where_x;
	}
	output_pr(map->adrX + i - 1, map->adrN + j - 4, 1);
}

void		first_fig(t_map *map)
{
	int	where_x;
	int	where_n;

	if (map->adrX - map->nadrX >= 0)
		where_x = -1;
	else
		where_x = 1;
	if (map->adrN - map->nadrN >= 0)
		where_n = -1;
	else
		where_n = 1;
	chek_subst(map, where_x, where_n);
}
