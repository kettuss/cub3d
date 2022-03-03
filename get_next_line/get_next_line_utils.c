#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	s1 = (char *)malloc(sizeof(*str) * i + 1);
	if (!s1)
		return (0);
	while (str[j])
	{
		s1[j] = str[j];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s2;

	s2 = (char *)str;
	while (*s2 != (unsigned char)c)
	{
		if (*s2 == '\0')
		{
			return (0);
		}
		s2++;
	}
	return (s2);
}

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((unsigned long)dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if ((!s1 || !s2) || (!s1 && !s2))
		return (0);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
