//
// Created by Iraida Kathrine on 3/2/22.
//

#include "../includes/cub_3D.h"

void ft_check_wall(t_cub *cub) //TODO: !!!
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

void ft_check_player_position(t_cub *cub)
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
    //TODO!!!
//    if ((cub->map_N + cub->map_S + cub->map_E + cub->map_W) != 1)
//        exit_cube(1);
}

void ft_check_path_images(t_cub *cub)
{
    int i;
    int j;
    int k;

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
            if ((cub->map[i][0] == 'N' && cub->map[i][1] == 'O') || (cub->map[i][0] == 'S' && cub->map[i][1] == 'O'))
                ft_utils_for_NO_and_SO(cub, i, j);
            else if ((cub->map[i][0] == 'W' && cub->map[i][1] == 'E') || (cub->map[i][0] == 'E' && cub->map[i][1] == 'A'))
                ft_utils_for_WE_and_EA(cub, i, j);
            else if (cub->map[i][0] == 'F' || cub->map[i][0] == 'C')
                ft_utils_for_colors(cub, i, j, k);
            break;
        }
        i++;
    }
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

int ft_check_before_map(char *cub)
{
    int i;
    int count_strings_before;

    i = 0;
    count_strings_before = 0;
       if (((cub[i] == 'N' || cub[i] == 'S') && cub[i + 1] == 'O')
            || (cub[i] == 'W' && cub[i + 1] == 'E') || (cub[i] == 'E' && cub[i + 1] == 'A')
            || (cub[i] == 'F' && cub[i + 1] == ' ') || (cub[i] == 'C' && cub[i + 1] == ' '))
           count_strings_before++;
    return (count_strings_before);
}

void checker_map(t_cub *cub, char **argv)
{
    ft_check_file_extention(argv); //check ".cub"
    ft_check_path_images(cub); //check NO, SO, WE, EA, F, C
    ft_check_player_position(cub); //check N, S, W, E
    //ft_check_wall(cub);
}
