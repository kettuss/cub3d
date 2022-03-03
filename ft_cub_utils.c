//
// Created by Iraida Kathrine on 3/3/22.
//

#include "cub.h"

size_t	ft_strlen_main(const char *str)
{
    int	i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*ft_strdup_main(const char *str)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	i;
    size_t	j;
    char	*newstr;

    if (!s || len <= 0 || start >= ft_strlen_main(s))
        return (ft_strdup_main(""));
    else
    {
        j = ft_strlen_main(&s[start]);
        if (j < len)
            len = j;
        newstr = malloc((len + 1) * sizeof(char));
        if (!(newstr))
            return (NULL);
        i = start;
        while (s[i] && (i - start) < len)
        {
            newstr[i - start] = s[i];
            i = i + 1;
        }
        newstr[i - start] = '\0';
        return (newstr);
    }
}

//int ft_check_read_path(char *cub)
//{
//    FILE *files;
//
//    files = fopen(cub, "r");
//    if (files)
//        return 1;
//    return 0;
//}