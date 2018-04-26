/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:32:36 by ismus             #+#    #+#             */
/*   Updated: 2018/04/26 16:32:37 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*check_data(int argc, char **argv)
{
	char *line;
	char *p1;

	if (get_next_line(0, &line) && ft_strncmp("error:\0", line, 4) == 0)
	{
		ft_printf("\x1b[1;31merror\n");
		free(line);
		return (0);
	}
	free(line);
	while (get_next_line(0, &line) && line[0] != '$')
		free(line);
	if (argc == 2 && ft_strcmp("enter\0", argv[1]) != 0 &&
		ft_strcmp("result\0", argv[1]) != 0)
	{
		ft_printf("\x1b[1;31minvalid input\n");
		return (0);
	}
	p1 = ft_strjoin("Player 🏠 : ", line + 14);
	free(line);
	return (p1);
}
