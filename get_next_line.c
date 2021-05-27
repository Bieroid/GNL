/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htommy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:40:50 by htommy            #+#    #+#             */
/*   Updated: 2021/05/27 14:40:51 by htommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read(int fd, char *ost, int BUFF_SIZE)
{
	int	a;

	ost = malloc(sizeof(char) * BUFF_SIZE);
	if (ost == 0)
		return (0);
	a = read(fd, ost, BUFF_SIZE + 1);
	if (a == 0)
		return (0);
	ost[a] = '\0';
	return (ost);
}

static char	*ft_zapis(char *ost)
{
	int		a;
	int		b;
	char 	*cpy;

	a = 0;
	b = 0;
	while (ost[a] != '\0')
		a++;
	while (ost[a] != '\n')
		b++;
	a = a - b;
	cpy = malloc(sizeof(char) * a);
	if (cpy == 0)
		return (0);
	a = 0;
	while (ost[b] != '\0')
	{
		cpy[a] = ost[b];
		b++;
		a++;
	}
	return (cpy);
}

static char *ft_perep(char *ost, char **line)
{
	int	a;

	a = 0;
	while ((ost[a] != '\n') || (ost[a] != '\0'))
		a++;
	if (ost[a] == '\n')
		a--;
	*line = malloc(sizeof(char) * a);
	if (*line == 0)
		return (0);
	while (a >= 0)
	{
		*line[a] = ost[a];
		a--;
	}
	return (*line);
}

int get_next_line(int fd, char **line)
{
	static char	*ost;
	int			a;
	int 		b;

	a = 0;
	b = 0;
	// начало цикла с у словием возможности считывания
	while (ost[a] != '\0')
	{
		if (ost[a] == '\n')
		{
			*line = ft_perep(ost, line);
			ost = ft_zapis(ost);
			// проверка возврата на ошибку
			return (1);
		}
		a++;
	}
	ost = ft_read(fd, ost, BUFF_SIZE);
	while (ost[b] != '\0')
		b++;
	if (b < BUFF_SIZE)
	{
		*line = ft_perep(ost, line);
		ost = ft_zapis(ost);
		// проверка возврата на ошибку
		return (0);
	}
	// решить проблемы с записью в буфер
	// Запись в буфер
	// }
}

// to do list -> обработка ошибок, сокращение через strjoin, написание тестов