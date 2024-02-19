#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*get_read_save(int fd, char *save);
char	*get_line(char *save);
char	*get_rest(char *save);
size_t	str_len(char *s);
char	*str_chr(char *save, int newline);
char    *str_join(char *save, char *buffer);
size_t	len_line(char *line);
#endif
