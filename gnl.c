#include "get_next.h"
#include <fcntl.h>

/*int	ft_prov(char *str)
{
	int a;

	a = 0;
	while ((str[a] != '\0') && (str[a] != '\n'))
		a++;
    if (str[a] == '\n')
        return (1);
    else if (str[a] == '\0')
        return (2);
    else
        return (0);
}

int	get_next_line(int fd, char **line)
{
    static char *ost;
    char        *str;

    if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
    if (ft_strlen(ost) == 0)
        ost = ft_strdup("");
    str = malloc(sizeof(char) * BUFFER_SIZE + 1);
    while (read(fd, str, BUFFER_SIZE))
    {
        str[BUFFER_SIZE]  = '\0';
        ost = ft_strjoin(ost, str);
        if (ft_prov(ost) == 1)
            {
                *line = ft_substr(ost, 0, ft_strchr(ost, '\n'));
                ost = ft_substr(ost, ft_strchr(ost, '\n') + 1, ft_strlen(ost));
                printf("posle ost = [%s]\n", ost);
                free(str);
                printf("ost = [%s]\n", ost);
                return (1);
            }
    }
    *line = ft_substr(ost, 0, ft_strlen(ost));
    free(ost);
    return (0);
}

int main()
{
	char	*line;
	int 	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
    get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}*/

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

int main()
{
	char	*line;
	int 	fd;
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
    get_next_line(fd, &line);
	printf("%s\n", line);
}