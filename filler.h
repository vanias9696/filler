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

typedef struct		s_map
{
	char			sym;
	int				adrx;
	int				adrn;
	char			nsym;
	int				where_x;
	int				nadrx;
	int				nadrn;
	int				last_x;
	int				last_n;
	int				is_block_l;
	int				is_block_r;
	int				llast_x;
	int				block_x;
	int				block_n;
	char			**map;
	char			**fig;
	int				map_x;
	int				map_n;
	int				fig_x;
	int				fig_n;
	int				wall_x;
	int				inv;
	int				nn;
}					t_map;

int					output_pr(int x, int y, int fd, t_map *map);
void				free_map_fig(t_map *map);
int					get_map_fig(t_map *map);
void				adr_xn(t_map *map);
int					check(t_map *map, int i, int j);
int					last_fig(t_map *map);
int					try_block_up(t_map *map);
int					is_overtook(t_map *map);
int					check_fig(t_map *map, int m);
int					check_wide(t_map *map, int i, int du, int n);
int					have_sym(int i, t_map *map);
int					last_check(t_map *map, int x, int y);
void				find_near(t_map *map);
int					b_r_down(t_map *map, int i, int n, int k);
int					b_l_down(t_map *map, int i);
int					b_r_up(t_map *map, int i, int n, int k);
int					b_l_up(t_map *map, int i);
int					joint_symb(t_map *map);
int					wide_block(t_map *map, int tu, int td, int i);

char				*check_data(int argc, char **argv);

#endif
