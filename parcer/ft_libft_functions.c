//
// Created by Iraida Kathrine on 3/6/22.
//

#include "../includes/cub_3D.h"

int	ft_count(char const *s, char c)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
            j++;
        i++;
    }
    return (j);
}

int	ft_lgthword(char const *s, char c, int k)
{
    int		i;
    int		j;

    i = k;
    j = 0;
    if (!s)
        return (0);
    while (s[i] != c && s[i] != '\0')
    {
        i++;
        j++;
    }
    return (j);
}

char	**ft_clean(char **str, int n)
{
    int		i;

    i = 0;
    if (!str || !n)
        return (0);
    while (i < n)
    {
        free(str[i]);
        i++;
    }
    free(str);
    return (NULL);
}

char	**ft_fillnewstr(char const *s, int n, char c, char **str)
{
    int		i;
    int		j;
    int		lgth;
    int		k;

    i = 0;
    k = 0;
    if (!s || !str)
        return (0);
    while (i < n)
    {
        j = 0;
        while (s[k] == c)
            k++;
        lgth = ft_lgthword(s, c, k);
        str[i] = (char *)malloc(sizeof(char) * (lgth + 1));
        if (!(str[i]))
            return (ft_clean(str, i));
        while (s[k] && s[k] != c)
            str[i][j++] = s[k++];
        str[i][j] = '\0';
        i++;
    }
    str[i] = 0;
    return (str);
}

char	**ft_split(char const *s, char c)
{
    char	**str;
    int		n;

    if (!s)
        return (NULL);
    n = ft_count(s, c);
    str = (char **)malloc(sizeof(char *) * (n + 1));
    if (!str)
        return (NULL);
    str = ft_fillnewstr(s, n, c, str);
    return (str);
}

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t    i;

    i = 0;
    while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i] && i < n)
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *s)
{
    unsigned int	res;
    int				i;
    int				k;

    k = 1;
    i = 0;
    res = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\f'
           || s[i] == '\r' || s[i] == '\n' || s[i] == '\v')
        i++;
    if (s[i] == '+' || s[i] == '-')
        if (s[i++] == '-')
            k = -1;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return ((int)(k * res));
}