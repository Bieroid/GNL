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
#include <fcntl.h>

size_t	ft_prov(char *str)
{
	int a;

	a = 0;
	while ((str[a] != '\0') && (str[a] != '\n'))
		a++;
	return (a);
}

int	get_next_line(int fd, char **line)
{
	static char *ost;
	char 		*str;
	char 		*del;
	int 		a;
	if (ft_strlen(ost) == 0)
		ost = strdup("");
	str = calloc(BUFFER_SIZE, sizeof(char));

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || (read(fd, str, 0) < 0))
	{
		return (-1);
	}

	while ((a = read(fd, str, BUFFER_SIZE) != 0))
	{
		del = ost;
		ost = ft_strjoin(ost, str);
		free(del);
		if (ft_strchr(ost, '\n'))
			break ;
	}
	if (ost == NULL)
	{
		*line = strdup("");
	}
	else
	{
		*line = ft_substr(ost, 0, ft_prov(ost));
	}
	if (ft_strchr(ost, '\n'))
		ost = ft_substr(ost, ft_prov(ost) + 1, ft_strlen(ost));
	else
	{
		free(str);
		free(ost);
		return (0);
	}
	free(str);
	return (1);
}

/*int main()
{
	char	*line;
	int 	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	sleep (10);
}*/
