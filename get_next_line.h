#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//# define BUFFER_SIZE 5

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr (const char *str, int ch);
char	*ft_strdup(const char *str);

#endif