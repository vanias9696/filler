/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:24:36 by ismus             #+#    #+#             */
/*   Updated: 2017/11/03 18:24:37 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	emp(int n, char c, const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (n);
		i++;
	}
	return (-1);
}

static int	nch(const char *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i == 0)
			while (s[i] == c)
				i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				n++;
		}
	}
	return (emp(n, c, s));
}

static int	wlen(char const *s, char c)
{
	int l;

	l = 0;
	while (*(s + l) != c && *(s + l) != '\0')
		l++;
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n;
	char	**new;
	int		i;
	int		t;

	if (!s)
		return (0);
	n = nch(s, c) + 1;
	new = (char **)malloc(sizeof(char *) * (n + 1));
	if (new == NULL)
		return (0);
	i = -1;
	while (++i < n)
	{
		while (*s == c)
			s++;
		new[i] = (char *)malloc(wlen(s, c) + 1);
		t = 0;
		while (*s != c && *s != '\0')
			new[i][t++] = *s++;
		new[i][t] = '\0';
	}
	new[i] = NULL;
	return (new);
}
