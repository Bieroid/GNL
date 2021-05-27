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

size_t	ft_strlen(const char *s)
{
	int	a;

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
	int		a;
	int		b;
	int		c;
	char	*s;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	c = -1;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	s = ft_calloc(sizeof(char), (a + b) + 1);
	if (s == 0)
		return (0);
	while (++c <= a)
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