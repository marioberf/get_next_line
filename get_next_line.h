#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 67
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*join(char *stash, char *buffer);
char	*truncated(char *s, char dlmr);
char	*line_parse(char *s, char dlmr);
#endif