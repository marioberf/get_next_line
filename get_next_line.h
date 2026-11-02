#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 67
# endif

typedef	struct
{
	size_t 	str_len;
	char	*str;
} Parser;

char	*get_next_line(int fd);
Parser	truncated(char *s, char dlmr);
Parser	line_parse(char *s, char dlmr);
#endif