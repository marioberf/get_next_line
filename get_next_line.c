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
	char		*buffer = NULL;
	static char	*stash;
	ssize_t		bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!in_line(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			free(buffer);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = join(stash, buffer);
	}
	free(buffer);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = line_parse(stash, '\n');
	stash = truncated(stash, '\n');
	return (line);
}

/* int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 16299)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);	
} */