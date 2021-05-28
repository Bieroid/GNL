/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htommy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:26:18 by htommy            #+#    #+#             */
/*   Updated: 2021/05/27 17:26:20 by htommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	a;

	if (s == NULL)
		return (0);
	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	char	*s;

	a = 0;
	s = malloc(size * num);
	if (s == 0)
		return (0);
	while (a < (size * num))
	{
		s[a] = 0;
		a++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t 		a;
	size_t 		b;
	size_t		c;
	char		*s;

	c = -1;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	s = ft_calloc(sizeof(char), (a + b) + 1);
	if (s == 0)
		return (0);
	while (++c < a)
		s[c] = s1[c];
	c--;
	a = 0;
	while (a <= b)
	{
		s[c] = s2[a];
		a++;
		c++;
	}
	return (s);
}

static char 	*ft_socr1(size_t len, char const *s, unsigned int start)
{
	size_t	a;
	char	*sub;

	a = 0;
	sub = ft_calloc(sizeof(char), len + 1);
	if (sub == 0)
		return (0);
	while (a < len)
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

static char 	*ft_socr2(size_t a, unsigned int start, char const *s)
{
	char	*sub;

	sub = ft_calloc(sizeof(char), (a - start) + 1);
	if (sub == 0)
		return (0);
	a = 0;
	while (s[start] != '\0')
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*sub;

	if (s == 0)
		return (0);
	a = ft_strlen(s);
	if (start > a)
	{
		sub = ft_calloc(sizeof(char), 1);
		if (sub == 0)
			return (0);
		return (sub);
	}
	if (a - start > len)
		sub = ft_socr1(len, s, start);
	else
		sub = ft_socr2(a, start, s);
	return (sub);
}

char	*ft_strchr (const char *str, int ch)
{
	int	a;

	ch = ch % 256;
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == ch)
			return ((char *)&str[a]);
		a++;
	}
	if (str[a] == ch)
		return ((char *)&str[a]);
	return (0);
}