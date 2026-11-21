/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariober <mariober@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 10:14:30 by mariober          #+#    #+#             */
/*   Updated: 2026/11/21 10:14:32 by mariober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

static int	readerr(ssize_t bytes, char **stash, char *buffer)
{
	if (bytes < 0)
	{
		free(*stash);
		free(buffer);
		*stash = NULL;
		return (1);
	}
	else
		return (0);
}

static int	eof(char **stash)
{
	if (!*stash || !**stash)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash[1024];
	ssize_t		bytes;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!in_line(stash[fd], '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (readerr(bytes, &stash[fd], buffer))
			return (NULL);
		buffer[bytes] = '\0';
		stash[fd] = join(stash[fd], buffer);
	}
	free(buffer);
	if (eof(&stash[fd]))
		return (NULL);
	line = line_parse(stash[fd], '\n');
	stash[fd] = truncated(stash[fd], '\n');
	return (line);
}

/* int	main()
{
	char	*c;
	int fd = open("test1.txt", O_RDONLY);
	int fd2= open("test2.txt", O_RDONLY);
	while ((c = get_next_line(fd)))
	{
		printf("%s", c);
		//c = get_next_line(fd);
		free(c);
	}
	printf("%s\n", get_next_line(fd2));
	close(fd);
	close(fd2);
	return (0);	
} */
