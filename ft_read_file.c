//
// Created by Iraida Kathrine on 3/2/22.
//

#include "cub.h"

int    ft_str_len(t_cub *cub)
{
    int    j;

    j = 0;
    cub->str_col = 0;
    while (cub->map[0][j])
    {
        cub->str_col++;
        j++;
    }
    return (cub->str_col);
}

char    *ft_str_char(const char *s, char c)
{
    int    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (unsigned char)c)
            return ((char *)s + i);
        i++;
    }
    if (c == '\0')
        return ((char *)s + i);
    return (NULL);
}

void    ft_str_number(t_cub *cub, char **argv)
{
    int        fd;
    char    *line;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_cube(6);
    cub->str_num = 1;
    while (get_next_line(fd, &line))
    {
        cub->str_num++;
        free(line);
    }
    free(line);
}

void read_map_file(char **argv, t_cub *cub)
{
    int i;
    int k;
    char *line;
    int fd;

    i = 0;
    k = 1;
    ft_str_number(cub, argv);
    cub->map = (char **)malloc(sizeof(char *) * (cub->str_num + 2));
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_cube(6);
    while(k)
    {
        k = get_next_line(fd, &line);
        cub->map[i] = ft_strdup(line);
        printf("%s\n", cub->map[i]);
        i++;
        free(line);
    }
    if (k == -1)
        exit_cube(6);
    cub->map[i] = NULL;
}