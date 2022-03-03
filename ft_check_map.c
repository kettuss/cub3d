//
// Created by Iraida Kathrine on 3/2/22.
//

#include "cub.h"

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

void ft_check_wall(t_cub *cub)
{
    int i_first;
    int j_first;
    int i_last;
    int j_last;

    i_first = 0;
    i_last = cub->str_num - 1;
    j_last = (ft_str_len(cub) - 1);
    while(cub->map[i_first])
    {
        j_first = 0;
        while(cub->map[i_first][j_first])
        {
            if (cub->map[0][j_first] != '1' || cub->map[i_first][0] != '1' || cub->map[i_first][j_last] != '1' || cub->map[i_last][j_first] != '1' || !ft_str_char(CHECK, cub->map[i_first][j_first]))
                exit_cube(1);
            j_first++;
        }
        i_first++;
    }
}

void ft_check_enter_thing_stop(t_cub *cub)
{
    int i;
    int j;


    i = 0;
    cub->map_N = 0;
    cub->map_S = 0;
    cub->map_E = 0;
    cub->map_W = 0;
    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if (cub->map[i][j] == 'N' && ((cub->map[i][j + 1] == '1' || cub->map[i][j + 1] == '0') || (cub->map[i][j - 1] == '1' || cub->map[i][j - 1] == '0')))
                cub->map_N = 1;
            if (cub->map[i][j] == 'S' && ((cub->map[i][j + 1] == '1' || cub->map[i][j + 1] == '0') || (cub->map[i][j - 1] == '1' || cub->map[i][j - 1] == '0')))
                cub->map_S = 1;
            if (cub->map[i][j] == 'E' && ((cub->map[i][j + 1] == '1' || cub->map[i][j + 1] == '0') || (cub->map[i][j - 1] == '1' || cub->map[i][j - 1] == '0')))
                cub->map_E = 1;
            if (cub->map[i][j] == 'W' && ((cub->map[i][j + 1] == '1' || cub->map[i][j + 1] == '0') || (cub->map[i][j - 1] == '1' || cub->map[i][j - 1] == '0')))
                cub->map_W = 1;
            j++;
        }
        i++;
    }
    printf("%d\n", cub->map_N + cub->map_S + cub->map_E + cub->map_W);
    if ((cub->map_N + cub->map_S + cub->map_E + cub->map_W) != 1)
        exit_cube(1);
}

void ft_check_path_images(t_cub *cub)
{
    int i;
    int j;
    int k;
    //int check_read_path;

    i = 0;
    cub->map_no = NULL;
    cub->map_so = NULL;
    cub->map_we = NULL;
    cub->map_ea = NULL;
    cub->map_f = NULL;
    cub->map_c = NULL;
    while (cub->map[i])
    {
        j = 0;
        k = 0;
        while (cub->map[i][j])
        {
            if (cub->map[i][0] == 'N' && cub->map[i][1] == 'O')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_no = ft_substr(cub->map[i], 3, k);
                //check_read_path = ft_check_read_path(cub->map_no);
            }
            else if (cub->map[i][0] == 'S' && cub->map[i][1] == 'O')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_so = ft_substr(cub->map[i], 3, k);
            }
            else if (cub->map[i][0] == 'W' && cub->map[i][1] == 'E')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_we = ft_substr(cub->map[i], 3, k);
            }
            else if (cub->map[i][0] == 'E' && cub->map[i][1] == 'A')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_ea = ft_substr(cub->map[i], 3, k);
            }
            else if (cub->map[i][0] == 'F')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_f = ft_substr(cub->map[i], 2, k);
            }
            else if (cub->map[i][0] == 'C')
            {
                j = j + 2;
                while (cub->map[i][j] != '\n')
                {
                    k++;
                    j++;
                }
                cub->map_c = ft_substr(cub->map[i], 2, k);
            }
            break;
        }
        i++;
    }
    printf("%s\n", cub->map_no);
    printf("%s\n", cub->map_so);
    printf("%s\n", cub->map_we);
    printf("%s\n", cub->map_ea);
    printf("%s\n", cub->map_f);
    printf("%s\n", cub->map_c);
}

int ft_check_file_extention(char **argv)
{
    int len;

    len = ft_strlen(*argv);
    if (argv == 0)
        return (0);
    if (len < 5)
        return (0);
    if (ft_strncmp(*(argv + len), ".cub", 4) != 0)
        return (0);
    return (1);
}


void checker_map(t_cub *cub, char **argv)
{
    //ft_check_wall(cub);

    ft_check_enter_thing_stop(cub);
    ft_check_path_images(cub);
    ft_check_file_extention(argv); //check ".cub"
}
