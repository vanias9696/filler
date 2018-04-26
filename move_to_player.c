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

static void	rotation_180(t_map *map, int i, int k, char **rmap)
{
	char	**rfig;

	rmap = (char **)malloc(sizeof(rmap) * (map->map_x + 2));
	rmap[map->map_x + 1] = 0;
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
	map->adrx = map->map_x - map->adrx;
	map->adrn = map->map_n + 7 - map->adrn;
	map->nadrx = map->map_x - map->nadrx;
	map->nadrn = map->map_n + 7 - map->nadrn;
	map->where_x = map->adrx > map->nadrx ? -1 : 1;
	rotation_180(map, 0, 1, 0);
	map->inv = 1;
	if (map->is_block_l == 0 || map->is_block_r == 0)
		is_block(map);
	find_near(map);
	if (is_overtook(map) == 1)
		return (1);
	if (joint_symb(map) == 1)
		return (1);
	if (try_block_up(map) == 1)
		return (1);
	return (last_check(map, map->map_x, map->map_n + 3) == 0 ? 0 : 1);
}

static int	move_to_pl(t_map *map)
{
	map->wall_x = 0;
	if (map->adrx > map->nadrx && map->adrn > map->nadrn)
		return (var_inverted(map));
	if (map->is_block_l == 0 || map->is_block_r == 0)
		is_block(map);
	find_near(map);
	if (is_overtook(map) == 1)
		return (1);
	if (joint_symb(map) == 1)
		return (1);
	if (try_block_up(map) == 1)
		return (1);
	return (last_check(map, 1, 4) == 0 ? 0 : 1);
}

int			last_fig(t_map *map)
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
			break ;
		}
		free_map_fig(map);
	}
	return (0);
}
