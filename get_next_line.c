#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash;
	ssize_t		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE + 1] = '\0';

	if (bytes <= 0)
		return (NULL);
	while (!buffer[ft_strlen(line_parse(buffer, '\n'))])
		read(fd, buffer, BUFFER_SIZE);
	stash = line_parse(buffer, '\n');
	stash = join(buffer, stash);

}

/* char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*stash;
	int		bytes;

	if (!buffer)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		while (!buffer[line_parse(buffer,'\n').str_len])
			read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		stash = malloc(truncated(buffer, '\n').str_len + line_parse(buffer, '\n').str_len);
		stash = buffer;
		return (line_parse(stash, '\n').str);
	}
	else
	{
		stash = malloc(truncated(buffer, '\n').str_len + line_parse(buffer, '\n').str_len);
		// stash = buffer;
		stash = join(buffer, stash);
		buffer = malloc(truncated(buffer, '\n').str_len);
		buffer = truncated(stash, '\n').str;
		return (line_parse(buffer, '\n').str);
	}

} */

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