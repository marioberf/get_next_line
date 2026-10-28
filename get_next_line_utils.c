#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_op(int fd, size_t b)
{
	ssize_t	read_b;

	static char	buffer[1024];
	read_b = read(fd, buffer, b);
	if (read_b > 0)
		buffer[read_b] = '\0';
	return (buffer);
}

size_t	total_bytes(int fd)
{
	ssize_t	i;
	char	*f;

	i = 1;
	f = read_op(fd, i);
	while (f[i])
	{
		f = read_op(fd, i);
		i++;
	}
	return (i);
}

void	parse_line(int fd)
{
	size_t	bytes;
	char *f;

	bytes = 0;
	f = read_op(fd, total_bytes(fd));
	while (f[bytes] != '\n')
	{
		if (!f[bytes])
			return ;
		if (f[bytes] == '\n')
			read_op(fd, bytes);
		bytes++;
	}
}

int	main()
{
	int fd = open("/home/mariober/Downloads/get_next_line/test.txt", O_RDONLY);
	parse_line(fd);
}