#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (!dst)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str && str[size])
		++size;
	return (size);
}

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	if (strlen + 1 < size)
		ft_memcpy(dest, str, strlen + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, str, size - 1);
		dest[size - 1] = '\0';
	}
	return (strlen);
}

char	*ft_strdup_and_free(char *s, char *del)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc((size));
	if (!dest || !s || size == 1)
	{
		free (del);
		free(dest);
		return (NULL);
	}
	ft_memcpy(dest, s, size);
	free(del);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
