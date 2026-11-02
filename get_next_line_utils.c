#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

Parser	truncated(char *s, char dlmr) // this goes to the stash
{
	Parser	p;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	flag;

	i = 0;
	j = 0;
	k = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == dlmr)
			flag = 1;
		while (s[i + j] && flag)
		{
			j++;
		}
		if (flag)
			break ;
		i++;
	}
	p.str = malloc(sizeof(char) * j);
	while ((k < j) && s[i + k])
	{
		p.str[k] = s[i + k];
		k++;
	}
	p.str_len = ft_strlen(p.str);
	return (p);
}

Parser	line_parse(char *s, char dlmr) // to return
{
	Parser	p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != dlmr && s[i])
		i++;
	p.str = malloc(sizeof(char) * i);
	while (j < i)
	{
		p.str[j] = s[j];
		j++;
	}
	p.str_len = ft_strlen(p.str);
	return (p);
}

/* #include <stdio.h>

int	main()
{
	char *str = "Hello\nWo\nrld";
	printf("%zu\n", line_parse(str, '\n').str);
	printf("%zu\n", truncated(str, '\n').str);
	return (0);
} */