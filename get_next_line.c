#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int	is_line(char *buffer, char dlmr)
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
	char		*line;
	ssize_t		bytes;

	bytes = 1;
	while (!is_line(buffer, '\n') && (bytes > 0))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!stash)
		{
			stash = malloc(bytes + 1);
		}
		// stash = join(buffer, stash);
		stash[bytes] = '\0';
	}
	if (bytes < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = malloc(ft_strlen(line_parse(stash, '\n')));
	line = line_parse(stash, '\n');
	stash = malloc(bytes + 1);
	stash = truncated(buffer, '\n');
	stash[bytes] = '\0';
	return (line);

}

/* int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 900)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	return (0);	
} */