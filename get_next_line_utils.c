#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	while (i < ft_strlen(stash))
	{
		str[i] = stash[i];
		i++;
	}
	while (j < ft_strlen(buffer))
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*truncated(char *s, char dlmr)
{
	char	*cp;
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == dlmr)
		{
			i++;
			break ;
		}
		i++;
	}
	j = 0;
	while (s[i + j])
		j++;
	cp = malloc(j + 1);
	j = 0;
	while (s[i + j])
	{
		cp[j] = s[i + j];
		j++;
	}
	cp[j] = '\0';
	free(s);
	return (cp);
}

char	*line_parse(char *s, char dlmr)
{
	char	*cp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((s[i] != dlmr) && s[i])
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	cp = malloc(i + 2);
	while (j < i)
	{
		cp[j] = s[j];
		j++;
	}
	if (s[j] == dlmr)
		cp[j++] = '\n';
	cp[j] = '\0';
	return (cp);
}

/* #include <stdio.h>

int	main()
{
	char *str = "hello\nworld\n124\n321";
	char *str3 = "\nhi";
	char *res;
	res = join(str, str3);
	printf("%s\n", res);
	return (0);
} */