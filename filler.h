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
	int				adrX;
	int				adrN;
	char			nsym;
	int				nadrX;
	int				nadrN;
	char			**map;
	char			**fig;
	int				map_x;
	int				map_n;
	int				fig_x;
	int				fig_n;
}					t_map;

#endif
