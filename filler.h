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
	int				where_x;
	int				nadrX;//не мій перший символ
	int				nadrN;
	int				last_x;
	int				last_n;
	int				llast_x;
	int				block_x;
	int				block_n;
	char			**map;// карта
	char			**fig;//нова фігура
	int				map_x;//розмір карти
	int				map_n;
	int				fig_x;//
	int				fig_n;
	int				wall_x;
}					t_map;

void				first_fig(t_map *map);
void				output_pr(int x, int y, int fd);
void				free_map_fig(t_map *map);
int					get_map_fig(t_map *map);
void				adr_xn(t_map *map);
int					check(t_map *map, int i, int j);
int					last_fig(t_map *map);
int					try_block_up(t_map *map);
int					find_wall(t_map *map, int n);
int					wide_block(t_map *map);
int					joint_symb(t_map *t_map);
#endif


