#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*read_op(int fd, size_t b)
{
	ssize_t	read_b;

	static char	buffer[BUFFER_SIZE];
	read_b = read(fd, buffer, b);
	if (read_b > 0)
		buffer[read_b] = '\0';
	return (buffer);
}

char	*parse_line(int fd)
{
	size_t	i;
	size_t	j;
	char	*f;
	char	*holder;

	f = read_op(fd, BUFFER_SIZE);
	i = 0;
	j = 0;
	while (f[i] != '\n' && f[i])
	{
		i++;
	}
	holder = malloc(sizeof(char) * i);
	while (j < i)
	{
		holder[j] = f[j];
		j++;
	}
	return (holder);
}

int	main()
{
	int fd = open("/home/lenovo/Descargas/get_next_line/test.txt", O_RDONLY);
	printf("%s\n", parse_line(fd));
}