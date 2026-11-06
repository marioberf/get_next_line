#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join(char *buffer, char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(ft_strlen(buffer) + ft_strlen(stash) + 1);
	i = 0;
	j = 0;
	while (i < ft_strlen(buffer))
	{
		str[i] = buffer[i];
		i++;
	}
	while (j < ft_strlen(stash))
	{
		str[i + j] = stash[j];
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
	while (s[i - 1] != dlmr && s[i])
		i++;
	cp = malloc(i + 1);
	while (j < i)
	{
		cp[j] = s[j];
		j++;
	}
	cp[j] = '\0';
	return (cp);
}

/* #include <stdio.h>

int	main()
{
	char *str = "Hello\nWo\nrld";
	//printf("%s", line_parse(str, '\n'));
	printf("%s", truncated(str, '\n'));
	return (0);
} */