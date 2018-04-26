/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:44:13 by ismus             #+#    #+#             */
/*   Updated: 2018/03/21 19:44:14 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			norm = check(map, map->adrx + i, map->adrn + j);
			if (norm == 0)
				j = j - where_n;
		}
		if (norm == 0)
			i = i - where_x;
	}
	output_pr(map->adrx + i - 1, map->adrn + j - 4, 1, map);
}

static void	first_fig(t_map *map)
{
	int	where_x;
	int	where_n;

	if (map->adrx - map->nadrx >= 0)
		where_x = -1;
	else
		where_x = 1;
	if (map->adrn - map->nadrn >= 0)
		where_n = -1;
	else
		where_n = 1;
	chek_subst(map, where_x, where_n);
}

int			main(void)
{
	t_map	*map;
	char	*line;

	map = ft_memalloc(sizeof(t_map));
	get_next_line(0, &line);
	map->sym = (line[10] == '1' ? 'O' : 'X');
	map->nsym = (line[10] == '1' ? 'X' : 'O');
	free(line);
	get_next_line(0, &line);
	map->map_x = ft_atoi(line + 8);
	map->map_n = ft_atoi(line + 9 + len_num(map->map_x));
	free(line);
	get_map_fig(map);
	adr_xn(map);
	first_fig(map);
	free_map_fig(map);
	last_fig(map);
	free(map);
	return (0);
}

int			have_sym(int i, t_map *map)
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
