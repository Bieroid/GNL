#include "get_next.h"

int     ft_strlen(const char *s)
{
    int a;

    if (s == NULL)
        return (0);
    a = 0;
    while (s[a] != '\0')
        a++;
    return (a);
}

void	*ft_calloc(int size, int num)
{
	int     a;
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

char    *ft_strjoin(const char *s1, const char *s2)
{
    int     a;
    int     b;
    int     c;
    char    *sum;

    a = ft_strlen(s1);
    b = ft_strlen(s2);
    c = 0;
    sum = malloc(sizeof(char) * ((a + b) + 1));
    if (sum == 0)
        return (0);
	sum[a + b + 1] = '\0';
    while (c < a)
    {
        sum[c] = s1[c];
        c++;
    }
    a = 0;
    while (a <= b)
    {
        sum[c] = s2[a];
        a++;
        c++;
    }
    return (sum);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		a;

	a = 0;
	while (str[a] != '\0')
		a++;
	s = malloc(sizeof(char) * a + 1);
	if (s == 0)
		return (0);
	while (a != -1)
	{
		s[a] = str[a];
		a--;
	}
	return (s);
}

int	ft_strchr (const char *str, int ch)
{
	int	a;

	ch = ch % 256;
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == ch)
			return (a);
		a++;
	}
	if (str[a] == ch)
		return (a);
	return (0);
}

static char 	*ft_socr1(int len, char const *s, unsigned int start)
{
	int	a;
	char	*sub;

	a = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == 0)
		return (0);
	sub[len] = '\0';
	while (a < len)
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

static char 	*ft_socr2(int a, unsigned int start, char const *s)
{
	char	*sub;

	sub = malloc(sizeof(char) * ((a - start) + 1));
	if (sub == 0)
		return (0);
	sub[a - start] = '\0';
	a = 0;
	while (s[start] != '\0')
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	int	a;
	char	*sub;

	if (s == 0)
		return (0);
	a = ft_strlen(s);
	if (start > a)
	{
		sub = malloc(sizeof(char) * 1);
		if (sub == 0)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	if (a - start > len)
		sub = ft_socr1(len, s, start);
	else
		sub = ft_socr2(a, start, s);
	free(s);
	return (sub);
}