/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariober <mariober@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:24:25 by mariober          #+#    #+#             */
/*   Updated: 2026/11/20 17:24:27 by mariober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (readerr(bytes, &stash, buffer))
			return (NULL);
		buffer[bytes] = '\0';
		stash = join(stash, buffer);
	}
	free(buffer);
	if (eof(&stash))
		return (NULL);
	line = line_parse(stash, '\n');
	stash = truncated(stash, '\n');
	return (line);
}
