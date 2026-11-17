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

	if (!stash)
		stash = "";
	i = 0;
	j = 0;
	str = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!str)
	{
		if (i > 0)
			free(stash);
		return (NULL);
	}
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
	if (i > 0)
		free(stash);
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
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	cp = malloc(ft_strlen(s + i) + 1);
	if (!cp)
	{
		free(s);
		return (NULL);
	}
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
	if (!cp)
		return (NULL);
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