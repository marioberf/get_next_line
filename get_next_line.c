#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*stash;

	if (!stash)
	{
		read(fd, buffer, BUFFER_SIZE);
		stash = malloc(truncated(buffer, '\n').str_len);
		stash = truncated(buffer, '\n').str;
		return (line_parse(buffer, '\n').str);
	}
	else
	{
		stash = malloc(truncated(buffer, '\n').str_len);
		read(fd, stash, line_parse(buffer, '\n').str_len);
		return (line_parse(stash, '\n').str);
	}

}

int	main()
{
	size_t	i;

	int fd = open("test.txt", O_RDONLY);
	i = 0;
	/* printf("%s\n", get_next_line(fd)); */
	while (i < 3)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
}