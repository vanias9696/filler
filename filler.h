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
	int				is_block_l;
	int				is_block_r;
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
	int				inv;
}					t_map;

void				first_fig(t_map *map);
void				output_pr(int x, int y, int fd, t_map *map);
void				free_map_fig(t_map *map);
int					get_map_fig(t_map *map);
void				adr_xn(t_map *map);
int					check(t_map *map, int i, int j);
int					last_fig(t_map *map);
int					try_block_up(t_map *map);
int					find_wall(t_map *map, int n);
int					wide_block(t_map *map);
int					joint_symb(t_map *t_map);
int					is_overtook(t_map *map);
int					square_near(t_map *map);
int					ft_while_n_block(char *str, char n, char c);
int					ft_rev_while_n_block(char *str, char n, char c, char m);
int					check_fig(t_map *map);
int					b_l_up(t_map *map, int i);
int					check_wide(t_map *map, int i, int du, int n);
#endif


