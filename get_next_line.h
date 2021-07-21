#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   5000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX      32
# endif

char    *get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *str1, char *str2);

#endif