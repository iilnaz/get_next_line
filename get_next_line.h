#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *str, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup_and_free(char *s, char *del);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif