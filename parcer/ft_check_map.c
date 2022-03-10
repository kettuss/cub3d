/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:43 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/10 15:38:13 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

void	ft_check_wall(t_cub *cub)
{
	int		max_size;
	int		i;
	int		j;
	t_cub	map;

	map.map = (char **)malloc(sizeof(char *) * (cub->str_num + 2));
	max_size = check_max_size_string(0, cub);
	map = check_spaces_in_the_map(cub, map, max_size);
	map.str_num = check_strings_count_in_the_map(map);
	check_wall_utils(map);
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '0')
				j = check_insaid_part_map(map, i, j);
			else
				j++;
		}
		i++;
	}
    free(map.map);
}

void	ft_check_path_images(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		k = 0;
		while (cub->map[i][j])
		{
			if ((cub->map[i][0] == 'N' && cub->map[i][1] == 'O')
				|| (cub->map[i][0] == 'S' && cub->map[i][1] == 'O'))
				ft_utils_for_no_and_so(cub, i, j);
			else if ((cub->map[i][0] == 'W' && cub->map[i][1] == 'E')
				|| (cub->map[i][0] == 'E' && cub->map[i][1] == 'A'))
				ft_utils_for_we_and_ea(cub, i, j);
			else if (cub->map[i][0] == 'F' || cub->map[i][0] == 'C')
				ft_utils_for_colors(cub, i, j, k);
			break ;
		}
		i++;
	}
}

int	ft_check_file_extention(char **argv)
{
	int	len;

	len = ft_strlen(*argv);
	if (argv == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(*(argv + len), ".cub", 4) != 0)
		return (0);
	return (1);
}

int	ft_check_before_map(char *cub)
{
	int	i;
	int	count_strings_before;

	i = 0;
	count_strings_before = 0;
	if (((cub[i] == 'N' || cub[i] == 'S') && cub[i + 1] == 'O')
		|| (cub[i] == 'W' && cub[i + 1] == 'E')
		|| (cub[i] == 'E' && cub[i + 1] == 'A')
		|| (cub[i] == 'F' && cub[i + 1] == ' ')
		|| (cub[i] == 'C' && cub[i + 1] == ' '))
		count_strings_before++;
	return (count_strings_before);
}

void	checker_map(t_cub *cub, char **argv)
{
	ft_check_file_extention(argv);
	ft_check_path_images(cub);
	ft_check_wall(cub);
}
