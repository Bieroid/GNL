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
#include <stdio.h>
#include <string.h>

size_t	ft_dlina(char *str)
{
	int a;

	a = 0;
	while ((str[a] != '\0') && (str[a] != '\n'))
		a++;
	return (a);
}

int	get_next_line(int fd, char **line)
{
	static char	*sum;
	char 		*per;
	int 		a;

	sum = NULL;
	per = calloc(BUFFER_SIZE + 1, sizeof(char));
	if ((per == 0) || (fd < 0) || (line = NULL) || (BUFFER_SIZE < 1))
		return (-1);
	while ((a = read(fd, per, BUFFER_SIZE)) != 0 )
	{
		per[a] = '\0';
		sum = ft_strjoin(sum, per);
		if (ft_strchr(sum, '\n'))
			break ;
	}
	if(sum == NULL)
		*line = strdup("");
	else
		*line = ft_substr(sum, 0, ft_dlina(sum));
	if (ft_strchr(sum, '\n'))
		sum = ft_substr(sum, ft_dlina(sum) + 1, ft_strlen(sum));
	else
	{
		free(sum);
		return (0);
	}
	return (1);
}