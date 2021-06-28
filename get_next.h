#ifndef GET_NEXT_H
# define GET_NEXT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
# define BUFFER_SIZE 5

int	    get_next_line(int fd, char **line);
int     ft_strlen(const char *s);
void	*ft_calloc(int size, int num);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
int	    ft_strchr (const char *str, int ch);
char	*ft_substr(char *s, unsigned int start, int len);

#endif