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
	map->nnadrN = map->nadrN;
	map->nnadrX = map->nadrX;
}

int			get_map_fig(t_map *map)
{
	char	*line;
	int		i;
	int		k;

	get_next_line(0, &line);
	map->map_x = ft_atoi(line + 8);
	map->map_n = ft_atoi(line + 9 + len_num(map->map_x));
	free(line);
	i = -1;
	map->map = (char **)malloc(sizeof(map->map) * (map->map_x + 2));
	map->map[map->map_x + 1] = 0;
	while (++i <= map->map_x)
		get_next_line(0, &(map->map[i]));
	get_next_line(0, &line);
	map->fig_x = ft_atoi(line + 6);
	map->fig_n = ft_atoi(line + 7 + len_num(map->fig_x));
	free(line);
	map->fig = (char **)malloc(sizeof(map->fig) * (map->fig_x + 1));
	map->fig[map->fig_x] = 0;
	i = 0;
	while (i < map->fig_x)
	{
		k = get_next_line(0, &(map->fig[i]));
		i++;
	}
	return (k);
}

void		free_map_fig(char **map, char **fig)
{
	int i;

	i = -1;
	while (map[++i] != 0)
		free(map[i]);
	free(map);
	i = -1;
	while (fig[++i] != 0)
		free(fig[i]);
	free(fig);
}

void		output_pr(int x, int y, int fd)
{
	ft_putnbr_fd(x, fd);
	write(1, " ", fd);
	ft_putnbr_fd(y, fd);
	write(1, "\n", fd);
}
