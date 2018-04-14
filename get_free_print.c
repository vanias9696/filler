/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_free_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:40:06 by ismus             #+#    #+#             */
/*   Updated: 2018/04/01 16:40:07 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	adr_n(t_map *map, int i)
{
	int z;

	z = ft_while_not_n(map->map[i], map->nsym);
	if (z > -1)
	{
		map->nadrX = i;
		map->nadrN = z;
	}
	else
	{
		z = ft_while_not_n(map->map[i], map->nsym + 32);
		if (z > -1)
		{
			map->nadrX = i;
			map->nadrN = z;
		}
	}
	return (z);
}

void		adr_xn(t_map *map)
{
	int		i;
	int		k;
	int		z;

	i = 1;
	k = -1;
	z = -1;
	while (map->map[i] != 0 && (k == -1 || z == -1))
	{
		if (k == -1)
		{
			k = ft_while_not_n(map->map[i], map->sym);
			if (k >= 0)
			{
				map->adrX = i;
				map->adrN = k;
			}
		}
		if (z == -1)
			z = adr_n(map, i);
		i++;
	}
	map->where_x = map->adrX > map->nadrX ? -1 : 1;
}

int			get_map_fig(t_map *map)
{
	char	*line;
	int		i;

	i = -1;
	map->map = (char **)malloc(sizeof(map->map) * (map->map_x + 2));
	map->map[map->map_x + 1] = 0;
	while (++i <= map->map_x)
		get_next_line(0, &(map->map[i]));
	get_next_line(0, &line);
	map->fig_x = ft_atoi(line + 6);
	map->fig_n = ft_atoi(line + 7 + len_num(map->fig_x));
	//free(line);
	map->fig = (char **)malloc(sizeof(map->fig) * (map->fig_x + 1));
	map->fig[map->fig_x] = 0;
	i = 0;
	while (i < map->fig_x)
	{
		get_next_line(0, &(map->fig[i]));
		i++;
	}
	return (1);
}

void		free_map_fig(t_map *map)
{
	int i;

	i = -1;
	if (map->map != 0)
	{
		while (map->map[++i] != 0)
			free(map->map[i]);
		free(map->map);
	}
	if (map->fig != 0)
	{
		i = -1;
		while (map->fig[++i] != 0)
			free(map->fig[i]);
		free(map->fig);
	}
}

void		output_pr(int x, int y, int fd)
{
	ft_putnbr_fd(x, fd);
	write(1, " ", fd);
	ft_putnbr_fd(y, fd);
	write(1, "\n", fd);
}
