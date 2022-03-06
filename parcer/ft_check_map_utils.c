/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:51:16 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/06 18:51:21 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

void ft_utils_for_colors(t_cub *cub, int i, int j, int k)
{
    if (cub->map[i][0] == 'F')
    {
        j = j + 2;
        while (cub->map[i][j] != '\n')
        {
            k++;
            j++;
        }
        cub->map_f = ft_substr(cub->map[i], 2, k);
        cub->map_f = ft_check_space_tab(cub->map_f);
        cub->color_f = ft_color_parse_to_int(cub->map_f);
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
        cub->map_c = ft_check_space_tab(cub->map_c);
        cub->color_c = ft_color_parse_to_int(cub->map_c);
    }
}

void ft_utils_for_NO_and_SO(t_cub *cub, int i, int j)
{
    if (cub->map[i][0] == 'N' && cub->map[i][1] == 'O')
    {
        j = j + 2;
        while (cub->map[i][j] != '\n')
            j++;
        cub->map_no = ft_substr(cub->map[i], 3, j);
//        printf("cub->map_no 111 = %s\n", cub->map_no);
        cub->map_no = ft_check_space_tab(cub->map_no);
//        printf("cub->map_no 222 = %s\n", cub->map_no);
    }
    else if (cub->map[i][0] == 'S' && cub->map[i][1] == 'O')
    {
        j = j + 2;
        while (cub->map[i][j] != '\n')
            j++;
        cub->map_so = ft_substr(cub->map[i], 3, j);
        cub->map_so = ft_check_space_tab(cub->map_so);
    }
}

void ft_utils_for_WE_and_EA(t_cub *cub, int i, int j)
{
    if (cub->map[i][0] == 'W' && cub->map[i][1] == 'E')
    {
        j = j + 2;
        while (cub->map[i][j] != '\n')
            j++;
        cub->map_we = ft_substr(cub->map[i], 3, j);
        cub->map_we = ft_check_space_tab(cub->map_we);
    }
    else if (cub->map[i][0] == 'E' && cub->map[i][1] == 'A')
    {
        j = j + 2;
        while (cub->map[i][j] != '\n')
            j++;
        cub->map_ea = ft_substr(cub->map[i], 3, j);
        cub->map_ea = ft_check_space_tab(cub->map_ea);
    }
}

char	*ft_check_space_tab(char *line)
{
    char	*cleaned_line;
    int		i;
    int		j;

    i = 0;
    j = 0;
    cleaned_line = malloc(sizeof(char *) * ft_strlen(line) + 1);
    if (!cleaned_line)
        return (NULL);
    while (line[i])
    {
        if ((line[i] == ' ' || line[i] == '\t')
            && (line[i + 1] == ' ' || line[i + 1] == '\t'))
            i = i + 2;
        else if (line[0] == '\0')
            cleaned_line[j] = line[0];
        else
        {
            cleaned_line[j] = line[i];
            i++;
            j++;
        }
    }
    cleaned_line[j] = '\0';
    return (cleaned_line);
}
