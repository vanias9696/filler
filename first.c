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

int		main(void)
{
	t_map	*map;
	char	*line;
	int		i;

	map = ft_memalloc(sizeof(t_map));
	get_next_line(0, &line);
	map->sym = (line[10] == '1' ? 'O' : 'X');
	map->nsym = (line[10] == '1' ? 'X' : 'O');
	free(line);
	i = get_map_fig(map);
	adr_xn(map);
	first_fig(map);
	free_map_fig(map->map, map->fig);
	while(i > 0)
	{
		i = get_map_fig(map);
		output_pr(0, 0, 1);
		free_map_fig(map->map, map->fig);
		//move_to_pl(map);
		//рухатись в напрямку іншого гравця, якщо ні перевірити де взагалі можна
		//очищення карти
	}
	return (0);
}
