#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*stash;
	char		*stash_aux;

	if (!stash)
	{
		read(fd, buffer, BUFFER_SIZE);
		stash = buffer;
		return (line_parse(buffer, '\n').str);
	}
	else
	{
		stash = truncated(stash, '\n').str;
		stash_aux = line_parse(stash, '\n').str;
		return (stash_aux);
	}

}

/* int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 20209)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);
} */