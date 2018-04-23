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
	if (map->nadrN < map->adrN)
		while (ft_rev_while_not_n(map->map[nx], map->nsym) < 2)
			nx = nx - map->where_x;
	else
		while (ft_while_not_n(map->map[nx], map->nsym) < 2)
			nx = nx - map->where_x;
	map->last_x = nx;
	if (map->nadrN < map->adrN)
		map->last_n = ft_rev_while_not_n(map->map[nx], map->nsym);
	else
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
	while (x >= 2 - map->fig_x && x <= map->map_x)
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
		output_pr(x - 1, n - 4, 1, map);
	else
		output_pr(0, 0, 1, map);
	return (ch == 1 ? 1 : 0);
}

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
				break;
			y = n == 3 - map->fig_n ? ++y : --y;
		}
		if (ch == 1)
			break;
		x = (du > 0 ? ++x : --x);
	}
	if (ch == 1)
	{
		output_pr(x - 1, y - 4, 1, map);
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
	//printf("wide\n");
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
	k = map->nadrN > map->adrN ? map->map_n + 3 : 3 - map->fig_n;
	if (k == map->map_n + 3 && map->is_block_r == 1)
		return (0);
	if (k == 3 - map->fig_n && map->is_block_l == 1)
		return (0);
	return (check_wide(map, i, td - tu, k) == 1 ? 1 : 0);
}

static void	is_block(t_map *map)
{
	int i;

	i = 1;
	while (i <= map->map_x && (map->is_block_r == 0 || map->is_block_l == 0))
	{
		if (map->map[i][5] == map->sym ||
			map->map[i][5] == map->sym + 32)
			map->is_block_l = 1;
		if (map->map[i][map->map_n + 2] == map->sym ||
			map->map[i][map->map_n + 2] == map->sym + 32)
			map->is_block_r = 1;
		i++;
	}
}
/*
static int	half_n(t_map *map)
{
	int x;


	x = map->map_x;
	while(ft_while_not_n(map->map[x], map->sym) < 0 &&
		ft_while_not_n(map->map[x], map->sym + 32) < 0)
		x--;
	if (map->is_block_l == 1 && map->is_block_r == 0 &&
		check_wide(map, x + map->fig_x, 1, map->map_n + 3) == 1)
		return (1);
	//я вже вище але ще по ширині далеко
	//if (if_long_away(map) == 1)
	//	return (1);
	printf("is half\n");

	x = 1;
	while (ft_while_not_n(map->map[x], map->sym) < 0 &&
		ft_while_not_n(map->map[x], map->sym + 32) < 0)
		++x;
//	if (x < map->map_x / 2)
//	{
		if (ft_while_n_block(map->map[x], map->sym, map->nsym) < 0 &&
			ft_while_n_block(map->map[x], map->sym + 32, map->nsym) < 0)
		{
			//printf("dklfnvslkd\n");
			while (x <= map->map_x && ft_while_n_block(map->map[x], map->sym, map->nsym) < 0 &&
				ft_while_n_block(map->map[x], map->sym + 32, map->nsym) < 0)
				x++;
			//printf("!!!\n");
			//x = x + 1;
		}
		//printf("wklfwle\n");
		x = x - map->fig_x + 1;
		//printf("here - %i\n", x);
		if (map->map_x - x <= map->map_x / 5)
			return (0);
		//printf("lkfjerl\n");
		return (b_l_up(map, x));

//	}
	return (0);
}
*/
static void	rotation_180(t_map *map)
{
	char **rmap;
	char **rfig;
	int i;
	int k;

	rmap = (char **)malloc(sizeof(rmap) * (map->map_x + 2));
	rmap[map->map_x + 1] = 0;
	i = 0;
	while (map->map[i] != 0)
		rmap[i++] = (char *)malloc(sizeof(rmap[0]) * (map->map_n + 1));
	rmap[0] = ft_strcpy(rmap[0], map->map[0] + 4);
	rmap[0] = joinfree("    ", rmap[0], 2);
	k = 1;
	while (--i != 0)
	{
		rmap[i] = ft_nstrncpy(rmap[i], map->map[k++] + 4);
		rmap[i] = joinfree("    ", rmap[i], 2);
	}
	rfig = (char **)malloc(sizeof(rfig) * (map->fig_x + 1));
	rfig[map->fig_x] = 0;
	i = 0;
	while (map->fig[i] != 0)
		rfig[i++] = (char *)malloc(sizeof(rfig[0]) * (map->fig_n + 1));
	k = 0;
	while (--i != -1)
		rfig[i] = ft_nstrncpy(rfig[i], map->fig[k++]);
	free_map_fig(map);
	map->map = rmap;
	map->fig = rfig;
}

static int	var_inverted(t_map *map)
{
	int x;

	x = 0;
	map->adrX = map->map_x - map->adrX;
	map->adrN = map->map_n + 7 - map->adrN;
	map->nadrX = map->map_x - map->nadrX;
	map->nadrN = map->map_n + 7 - map->nadrN;
	map->where_x = map->adrX > map->nadrX ? -1 : 1;
	rotation_180(map);
	//printf("block\n");
	map->inv = 1;
	if (map->is_block_l == 0 || map->is_block_r == 0)
		is_block(map);
	find_near(map);
	//блок праворуч як тільки появився блок ліворуч
	//скоріше обмежити по лівій стороні
	//printf("is_overtook\n");
	if (is_overtook(map) == 1)
		return (1);
	//printf("joint_symb\n");
	if (joint_symb(map) == 1)
		return (1);
	//printf("block\n");
	if (try_block_up(map) == 1)
		return (1);
	//printf("else\n");
	return (check_second(map, map->map_x, map->map_n + 3) == 0 ? 0 : 1);
}

static int	move_to_pl(t_map *map)
{
	map->wall_x = 0;
	//if ( map->adrX > map->nadrX && map->adrN > map->nadrN && half_n(map) == 1)
	//	return (1);
	if ( map->adrX > map->nadrX && map->adrN > map->nadrN)
		return (var_inverted(map));
	if (map->is_block_l == 0 || map->is_block_r == 0)
		is_block(map);
	find_near(map);
	//printf("not half\n");
	if (is_overtook(map) == 1)
		return (1);
	//printf("joint_symb\n");
	if (joint_symb(map) == 1)
		return (1);
	//printf("block\n");
	if (try_block_up(map) == 1)
		return (1);
	//printf("else\n");
	return (check_second(map, 1, 4) == 0 ? 0 : 1);
}

int		last_fig(t_map *map)
{
	int		k;
	char	*line;

	k = 1;
	map->is_block_l = 0;
	map->is_block_r = 0;
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
		break;
	}
	return (0);
}
