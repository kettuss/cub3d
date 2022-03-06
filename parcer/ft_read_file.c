//
// Created by Iraida Kathrine on 3/2/22.
//

#include "../includes/cub_3D.h"

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
    int count;

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
        if (k == -1)
            exit_cube(6);
        cub->map[i] = ft_strdup(line);
        if (!(cub->map[i][0] == ' ' || cub->map[i][0] == '1'))
           count = count + ft_check_before_map(cub->map[i]);
        else if (cub->map[i][0] == ' ' || cub->map[i][0] == '1')
        {
            if (count < 6)
                exit_cube(9);
        }
        //printf("%s\n", cub->map[i]);
        i++;
        free(line);
    }
//    if (k == -1)
//        exit_cube(6);
    cub->map[i] = NULL;
    //printf("%s\n", " ");
    read_map_card(cub);
}

void read_map_card(t_cub *cub) {
    int i;
    int j;
    t_cub map;

    i = 0;
    j = 0;
    map.map = (char **)malloc(sizeof(char *) * (cub->str_num + 2));
    while (i < cub->str_num)
    {
       if (((cub->map[i][0] == ' ' && (cub->map[i][1] == ' ' || cub->map[i][1] == '1')) || cub->map[i][0] == '1')
            || (cub->map[i][0] == '\0' && ((cub->map[i + 1][0] == ' ' || cub->map[i + 1][0] == '1') && (cub->map[i - 1][0] == ' ' || cub->map[i - 1][0] == '1'))))
        {
            map.map[j] = cub->map[i];
            printf("%s\n", map.map[j]);
            j++;
        }
        i++;
    }
    map.map[j] = NULL;
    i = 0;
    while (map.map[i] != NULL)
    {
        if (map.map[i][0] == '\0')
            exit_cube(1);
        i++;
    }
}