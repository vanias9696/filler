/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:58:43 by ismus             #+#    #+#             */
/*   Updated: 2017/12/07 15:58:44 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*correct_buf(int fd, t_list **list)
{
	t_list			*temp;

	temp = *list;
	while (temp)
	{
		if ((unsigned int)(temp->content_size) == (unsigned int)fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew(0, fd);
	temp->content_size = fd;
	ft_lstadd(list, temp);
	if (!(temp->content = malloc(BUFF_SIZE + 1)))
		return (0);
	ft_bzero(temp->content, BUFF_SIZE);
	return (temp);
}

static int		ft_free(t_list *temp, int nread, char **line)
{
	int		numbn;
	int		l;
	int		j;
	int		n;
	char	*str;

	numbn = ft_strlen(*line);
	if (nread == 0 && ft_strlen(temp->content) < 1)
		return (0);
	n = numbn + 1;
	l = ft_strlen(temp->content);
	j = 0;
	str = temp->content;
	while (j < l - n && j < l)
	{
		str[j] = str[j + n];
		j++;
	}
	while (j < l)
	{
		str[j] = '\0';
		j++;
	}
	return (1);
}

static int		fill_list(t_list *temp, char **line)
{
	int	numbn;

	if ((numbn = ft_while_not_n(temp->content, '\n')) && numbn < 0)
		numbn = ft_strlen(temp->content);
	if (!(*line = (char *)malloc(numbn + 1)))
		return (-1);
	*line = ft_strncpy(*line, temp->content, numbn);
	line[0][numbn] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*temp;
	int				nread;
	char			buf[BUFF_SIZE + 1];
	char			*free_cont;

	if (fd < 0 || line == NULL || read(fd, &buf, 0) < 0)
		return (-1);
	CHECKERROR((temp = correct_buf(fd, &list)));
	while ((nread = read(fd, &buf, BUFF_SIZE)) && nread != 0)
	{
		buf[nread] = '\0';
		free_cont = temp->content;
		CHECKERROR((temp->content = ft_strjoin(temp->content, buf)));
		free(free_cont);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (fill_list(temp, line) < 0)
		return (-1);
	return (ft_free(temp, nread, line) == 0 ? 0 : 1);
}
