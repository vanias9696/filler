/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:59:09 by ismus             #+#    #+#             */
/*   Updated: 2018/04/18 14:59:10 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	change_sym(char *line, char *p1, char *p2, int i)
{
	if (i == 1)
		read(1, 0, 1);
	i = 0;
	system("clear");
	ft_printf("\x1b[1;33m%s\n\x1b[0;32m%s\x1b[1;37m\n\n ", p1, p2);
	while (line[i] != '\0')
	{
		while ((line[i] <= '9' && line[i] >= '0') ||
			line[i] == '.' || line[i] == ' ' || line[i] == '\n')
		{
			ft_printf("%c ", line[i]);
			i++;
		}
		while (line[i] == 'o' || line[i] == 'O')
		{
			i++;
			ft_printf("🏠 ");
		}
		while (line[i] == 'x' || line[i] == 'X')
		{
			i++;
			ft_printf("🌲 ");
		}
	}
	write(1, "\n", 1);
}

void	get_map(char *map, char *p1, char *p2, int p)
{
	char *line;

	while (1)
	{
		get_next_line(0, &line);
		if (ft_strncmp(line, "Piece\0", 3) == 0)
			break ;
		if (map == 0)
			map = ft_strjoin(line, "\n\0");
		else
		{
			map = joinfree(map, "\n\0", 1);
			map = joinfree(map, line, 1);
		}
	}
	change_sym(map, p1, p2, p);
	free(map);
	while (ft_strncmp(line, "<got\0", 2) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	free(line);
}

char	*print_map(char *line, char *p1, char *p2, int p)
{
	char *map;

	while (get_next_line(0, &line))
	{
		map = 0;
		if (ft_strncmp(line, "Piece\0", 3) == 0)
		{
			while (ft_strncmp(line, "<got", 2) != 0)
			{
				free(line);
				get_next_line(0, &line);
			}
			free(line);
			get_next_line(0, &line);
		}
		if (ft_strncmp(line, "Plateau\0", 3) != 0)
			break ;
		free(line);
		get_map(map, p1, p2, p);
	}
	return (line);
}

void	who_win(char *str1, char *p1, char *p2)
{
	int one;
	int two;

	one = ft_atoi(str1 + 10);
	free(str1);
	get_next_line(0, &str1);
	two = ft_atoi(str1 + 10);
	free(str1);
	ft_printf("\x1b[1;33mPlayer 🏠 : %i\n\x1b[0;32mPlayer 🌲 : %i", one, two);
	ft_printf("\x1b[1;37m\n");
	if (one > two)
		str1 = p1;
	else if (one < two)
		str1 = p2;
	else
		str1 = ft_strjoin("pppppppppppppp", "friendship!");
	ft_printf("Win : %s\n", str1 + 14);
}

int		main(int argc, char **argv)
{
	char	*line;
	char	*p1;
	char	*p2;
	int		p;

	p1 = check_data(argc, argv);
	if (p1 == 0)
		return (0);
	p = 0;
	if (argc == 2 && ft_strcmp("enter\0", argv[1]) == 0)
		p = 1;
	else if (argc == 2 && ft_strcmp("result\0", argv[1]) == 0)
		p = 2;
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	p2 = ft_strjoin("Player 🌲 : ", line + 14);
	free(line);
	while (p == 2 && get_next_line(0, &line) && ft_strncmp("== ", line, 3) != 0)
		free(line);
	if (p != 2)
		line = print_map(line, p1, p2, p);
	who_win(line, p1, p2);
	return (0);
}
