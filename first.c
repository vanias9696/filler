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
#include <stdio.h>

void	new_map(t_map *map)
{
	int		i;
	int		k;
	int		z;

	i = 0;
	map->map = (char **)malloc(sizeof(map->map) * (map->map_x + 2));
	map->map[map->map_x + 1] = 0;
	while (i <= map->map_x)
	{
		get_next_line(0, &(map->map[i]));
		i++;
	}
	k = -1;
	z = -1;
	while (map->map[i] || (k != -1 && z != -1))
	{
		if (k == -1)
		{
			k = while_not_n(map->map[i], map->sym);
			if (k != -1)
			{
				map->adrX = i;
				map->adrN = k;

			}
		}
		if (z == -1)
		{
			z = while_not_n(map->map[i], map->nsym);
			if (k != -1)
			{
			map->nadrX = i;
			map->nadrN = z;

			}
		}
		i++;
	}
}

int		len_num(int n)
{
	int l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n > 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

void	player_map(char *line1, t_map *map)
{
	if(line1[10] == '1')
	{
		map->sym = 'O';
		map->nsym = 'X';
	}
	else if (line1[10] == '2')
	{
		map->sym = 'X';
		map->nsym = 'O';
	}
	free(line1);
	get_next_line(0, &line1);
	map->map_x = ft_atoi(line1 + 8);//розмір карти x i n
	map->map_n = ft_atoi(line1 + 9 + len_num(map->map_x));
}

void	get_fig(t_map *map)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	map->fig_x = ft_atoi(line + 6);//розмір карти x i n
	map->fig_n = ft_atoi(line + 7 + len_num(map->fig_x));
	map->fig = (char **)malloc(sizeof(map->fig) * (map->fig_x + 1));
	map->fig[map->fig_x] = 0;
	i = 0;
	while (i < map->fig_x)
	{
		get_next_line(0, &(map->fig[i]));
		i++;
	}
}

int		main(void)
{
	t_map	*map;
	char	*line1;

	map = (t_map *)malloc(sizeof(t_map));
	get_next_line(0, &line1);
	player_map(line1, map);//отримую номер мого гравця
	free(line1);
	new_map(map);
	while(1)
	{
		get_fig(map);
		move_to_pl(t_map *map);
		//рухатись в напрямку іншого гравця, якщо ні перевірити де взагалі можна
		//очищення карти
	}
	return (0);
}
