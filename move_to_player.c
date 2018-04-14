/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:37:59 by ismus             #+#    #+#             */
/*   Updated: 2018/03/29 14:38:00 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	find_near(t_map *map)
{
	int nx;

	nx = map->where_x == -1 ? 1 : map->map_x;
	while (ft_while_not_n(map->map[nx], map->nsym) < 2)
		nx = nx - map->where_x;
	map->last_x = nx;
	map->last_n = ft_while_not_n(map->map[nx], map->nsym);
}

static int	check_second(t_map *map, int x, int y)
{
	int where_x;
	int	where_n;
	int ch;
	int n;

	where_x = x == map->map_x ? -1 : 1;
	where_n = y == 4 ? 1 : -1;
	while (x >= 2 - map->fig_x && x <= map->map_x)//!!!!!!!!!!!!!!!!!!!!!!!!!
	{
		n = y;
		while(n <= map->map_n + 3 && n >= 5 - map->fig_n)
		{
			ch = check(map, x, n);
			if (ch == 1)
				break;
			n = n + where_n;
		}
		if (ch == 1)
			break;
		x = x + where_x;
	}
	if (ch == 1)
		output_pr(x - 1, n - 4, 1);
	else
		output_pr(0, 0, 1);
	return (ch == 1 ? 1 : 0);
}
/*
static void find_new(t_map *map)
{
	int i;
	int n;

	i = 1;
	map->llast_x = map->last_x;
	while(map->map[i] != 0)
	{
		n = ft_while_not_n(map->map[i], map->nsym + 32);
		if (n > 3)
		{
			map->last_n = n;
			break;
		}
		i++;
	}
	map->last_x = (i == map->map_x + 1 ? 0 : i);
}
*/
static int	check_wide(t_map *map, int i, int td, int tu)
{
	int n;
	int x;
	int y;
	int ch;

	n = ft_while_not_n(map->map[i], map->sym);
	x = td > tu ? i - map->fig_x : i;
	ch = 0;
	while (x >= i - map->fig_x && x <= i && ch != 1)
	{
		y = n - 3 > map->map_n - n ? 3 : map->map_n + 3;
		while (y >= 3 && y <= map->map_n + 3 && ch != 1)
		{
			ch = check(map, x, y) == 1;
			if (ch == 1)
				break;
			y = n - 3 > map->map_n - n ? ++y : --y;
		}
		if (ch == 1)
			break;
		x = (td > tu ? ++x : --x);
	}
	if (ch == 1)
	{
		output_pr(x - 1, y - 4, 1);
		return (1);
	}
	return (0);

}

int		wide_block(t_map *map)
{
	int i;
	int k;
	int tu;
	int td;

	tu = 0;
	td = 0;
	i = 1;
	while (ft_while_not_n(map->map[i], map->nsym) < 0 && 
		ft_while_not_n(map->map[i], map->nsym + 32) < 0)
	{
		i++;
		td++;
	}
	k = map->map_x;
	while (ft_while_not_n(map->map[k], map->nsym) < 0 &&
		ft_while_not_n(map->map[k], map->nsym + 32) < 0)
	{
		k--;
		tu++;
	}
	i = td > tu ? i : k;
	while (ft_while_not_n(map->map[i], map->sym) < 0)
	{
		i = td > tu ? --i : ++i;
		if (i < 1 || i > map->map_x)
			break;
	}
	if (i < 1 || i > map->map_x)
		return (0);
	printf("wide_block\n");
	return (check_wide(map, i, td, tu) == 1 ? 1 : 0);
}

static int	move_to_pl(t_map *map)
{
	int n;
	int x;

	map->wall_x = 0;
	find_near(map);
	//find_new(map);
	if (joint_symb(map) == 1)
		return (1);
	if (try_block_up(map) == 1)
		return (1);
	printf("not block\n");
	n = map->wall_x > 0 ? 4 : map->map_n + 3;
	map->wall_x = map->wall_x < 0 ? -1 * map->wall_x : map->wall_x;
	x = map->wall_x < map->nadrX ? map->map_x : 1;
	return (check_second(map, x, n) == 0 ? 0 : 1);
}

int		last_fig(t_map *map)
{
	int		k;
	char	*line;

	k = 1;
	while (get_next_line(0, &line) > -1)
	{
		if (!line)
			return (0);
		map->map_x = ft_atoi(line + 8);
		map->map_n = ft_atoi(line + 9 + len_num(map->map_x));
		free(line);
		get_map_fig(map);
		if (move_to_pl(map) == 0)
		{
			free_map_fig(map);
			break;
		}
		free_map_fig(map);
	}
	return (0);
}
