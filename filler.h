/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:00:20 by ismus             #+#    #+#             */
/*   Updated: 2018/03/22 12:00:20 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "new_lib/libft.h"
# include "filler.h"

typedef struct		s_map
{
	char			sym;
	int				adrX;//перший символ
	int				adrN;
	char			nsym;
	int				nadrX;//не мій перший символ
	int				nadrN;
	char			**map;// карта
	char			**fig;//нова фігура
	int				map_x;//розмір карти
	int				map_n;
	int				fig_x;//
	int				fig_n;
	int				horiz;
	int				vertic;
}					t_map;

void				first_fig(t_map *map);
void				output_pr(int x, int y, int fd);
void				free_map_fig(char **map, char **fig);
int					get_map_fig(t_map *map);
void				adr_xn(t_map *map);
#endif


