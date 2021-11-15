#include "get_next_line.h"

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	free(s1);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	substr = (char *)malloc((len + 1));
	if (!substr)
		return (NULL);
	i = start;
	while (s[i] && i - start < len && start < ft_strlen(s))
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[i - start] = '\0';
	return (substr);
}

int	read_data(int fd, char **nl_symbol, char **remnant)
{
	int		rd;
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(buf);
		return (-1);
	}
	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0)
	{
		buf[rd] = 0;
		*remnant = ft_strjoin_and_free(*remnant, buf);
		*nl_symbol = ft_strchr(*remnant, '\n');
		if (*nl_symbol)
			break ;
		rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (rd);
}

char	*get_next_line(int fd)
{
	static char	*remnant[4096];
	char		*res;
	char		*nl_symbol;
	int			count_of_read;

	nl_symbol = NULL;
	count_of_read = read_data(fd, &nl_symbol, &remnant[fd]);
	if (count_of_read < 0 || !remnant[fd])
		return (NULL);
	else if (count_of_read == 0)
		nl_symbol = ft_strchr(remnant[fd], '\n');
	if (!nl_symbol)
	{
		res = remnant[fd];
		remnant[fd] = NULL;
		return (res);
	}
	res = ft_substr(remnant[fd], 0, nl_symbol - remnant[fd] + 1);
	remnant[fd] = ft_strdup_and_free(nl_symbol + 1, remnant[fd]);
	return (res);
}
