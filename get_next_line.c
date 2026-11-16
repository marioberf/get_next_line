#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int	in_line(char *buffer, char dlmr)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == dlmr)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;
	ssize_t		bytes;
	char		*line;
	int			i;

	while (!in_line(buffer, '\n') && (bytes > 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = malloc(bytes + 1);
		if (!stash)
		{
			i = 0;
			while (buffer[i])
			{
				stash[i] = buffer[i];
				i++;
			}
		}
		else
			stash = join(stash, buffer);
	}
	line = line_parse(stash, '\n');
	stash = truncated(stash, '\n');
	return (line); // free line es PDU
}

int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 2)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);	
}