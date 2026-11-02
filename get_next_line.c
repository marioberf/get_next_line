#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	ssize_t	read_b;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	char	*stash;
	static char	buffer[BUFFER_SIZE];
	read_b = read(fd, buffer, BUFFER_SIZE);

	stash = malloc(sizeof(char) * truncated(buffer, '\n').str_len);
	stash = truncated(buffer, '\n').str;
	buffer = malloc(sizeof(char) * truncated(buffer, '\n').str_len);
	buffer = stash;
	free(buffer);
	return (line_parse(buffer, '\n').str);
}

int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	// printf("%s\n", read_op(fd));
	while (i < 3)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
}