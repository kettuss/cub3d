//
// Created by Iraida Kathrine on 3/3/22.
//

#include "../includes/cub_3D.h"

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

int ft_check_read_path(char *cub)
{
    int files;

    files = open(cub, O_RDONLY);
    if (files > 0) {
        printf("%s", "File is open, good, cool etc.!!");
        return 1;
    }
    else {
        exit_cube(7);
        return (0);
    }
}

long ft_color_parse_to_int(char *cub)
{
    char **array;
    long color;
    int i;
    int *newArray;

    i = 0;
    array = ft_split(cub,',');
    newArray = (int *)malloc(sizeof(int *) + 1);
    if (!newArray)
        return (0);
    while (array[i] != (void *)0) {
        newArray[i] = ft_atoi(array[i]);
        i++;
    }
    if (i != 3)
        exit_cube(10);
    i = 0;
    while (i < 3)
    {
        if (newArray[i] < 0 || newArray[i] > 255)
        {
            exit_cube(11);
            break;
        }
        i++;
    }
    color = (1 << 24 | newArray[0] << 16 | newArray[1] << 8 | newArray[2]);
    return (color);
}