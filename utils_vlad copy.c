#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (!s)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		a;
	char	*dest;

	a = 0;
	while (src[a])
		a++;
	dest = malloc(a + 1);
	if (dest == 0)
		return (NULL);
	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strjoin_new(char *s1, char const *s2)
{
	char	*dest;
	int		a;
	int		l;

	if (!s1 && !s2)
		return (NULL);
	a = -1;
	l = 0;
	if (!s1)
		s1 = ft_strdup("");
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == 0)
		return (NULL);
	while (s1[++a])
		dest[a] = s1[a];
	while (s2[l])
		dest[a++] = s2[l++];
	dest[a] = '\0';
	free(s1);
	return (dest);
}
