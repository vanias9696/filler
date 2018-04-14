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
