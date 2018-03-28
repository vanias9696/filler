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
	char *line1;

	get_next_line(0, &line1);
	map->sym = map->sym + 0;
	printf("3 6\n");
}

void	which_player(char *line1, t_map *map)
{
	if(line1[10] == '1')
		map->sym = 'O';
	else if (line1[10] == '2')
		map->sym = 'X';
}

int		main(void)
{
	t_map	*map;
	char	*line1;

	map = (t_map *)malloc(sizeof(t_map));
	get_next_line(0, &line1);
	which_player(line1, map);//отримую номер мого гравця
	ft_putendl_fd(line1, 2);
	while (1)
	{
		new_map(map);
	}
	return (0);
}
