#include "get_next_line.h"

size_t	ft_strlen(char *s)
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

	str = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	i = 0;
	j = 0;
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
			break ;
		i++;
	}
	cp = malloc(i + 1);
	j = 0;
	while(s[i + j])
	{
		cp[j] = s[i + j];
		j++;
	}
	cp[i + j] = '\0';
	return (cp);
}

char	*line_parse(char *s, char dlmr)
{
	char	*cp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != dlmr)
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
	cp[j] = '\n';
	cp[j + 1] = '\0';
	return (cp);
}

#include <stdio.h>

int	main()
{
	char *str = "hello\nworld\n123\n321";
	printf("%s", line_parse(str, '\n'));
	printf("%s", truncated(str, '\n'));
	printf("%s", line_parse(str, '\n'));
	printf("%s\n", join(line_parse(str, '\n'), truncated(str, '\n')));
	return (0);
}