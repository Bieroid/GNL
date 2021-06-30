#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);

char	*ft_strdup(const char *src);
char	*ft_strjoin_new(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_check(char *save, int l);

#endif