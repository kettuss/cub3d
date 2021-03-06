/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:29:24 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/10 23:55:56 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

t_cub	check_spaces_in_the_map(t_cub *cub, t_cub map, int max_size)
{
	int		i;
	int		j;
	int		current_size;
	char	*temp;

	i = -1;
	j = 0;
	while (cub->map[++i])
	{
		if (cub->map[i][0] == ' ' || cub->map[i][0] == '1')
		{
			current_size = ft_strlen_main(cub->map[i]);
			map.map[j] = cub->map[i];
			if (current_size < max_size)
			{
				while (current_size < max_size)
				{
					temp = map.map[j];
					map.map[j] = ft_strjoin(map.map[j], " ");
					free(temp);
					current_size++;
				}
			}
			cub->map[i] = map.map[j];
			j++;
		}
	}
	map.map[j] = NULL;
	return (map);
}

int	check_strings_count_in_the_map(t_cub map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map.map[i])
	{
		if (map.map[i][0])
			j++;
		i++;
	}
	return (j);
}

void	check_wall_utils(t_cub map)
{
	int	i_first;
	int	j_first;
	int	i_last;
	int	j_last;

	i_first = 0;
	i_last = map.str_num - 1;
	j_last = (ft_str_len(&map) - 1);
	while (map.map[i_first])
	{
		j_first = 0;
		while (map.map[i_first][j_first])
		{
			if ((map.map[0][j_first] == '1' || map.map[0][j_first] == ' ')
				&& (map.map[i_first][0] == '1' || map.map[i_first][0] == ' ')
				&& (map.map[i_first][j_last] == '1'
				|| map.map[i_first][j_last] == ' ')
				&& (map.map[i_last][j_first] == '1'
				|| map.map[i_last][j_first] == ' '))
				j_first++;
			else
				exit_cube_card_util(1);
		}
		i_first++;
	}
}

int	check_insaid_part_map(t_cub map, int i, int j)
{
	if ((map.map[i - 1][j - 1] == '1'
		|| map.map[i - 1][j - 1] == '0') && (map.map[i][j - 1] == '1'
		|| map.map[i][j - 1] == '0') && (map.map[i + 1][j + 1] == '1'
		|| map.map[i + 1][j + 1] == '0') && (map.map[i - 1][j + 1] == '1'
		|| map.map[i - 1][j + 1] == '0') && (map.map[i - 1][j] == '1'
		|| map.map[i - 1][j] == '0') && (map.map[i + 1][j] == '1'
		|| map.map[i + 1][j] == '0') && (map.map[i + 1][j - 1] == '1'
		|| map.map[i + 1][j - 1] == '0') && (map.map[i][j + 1] == '1'
		|| map.map[i][j + 1] == '0'))
		j++;
	else
		exit_cube_card_util(1);
	return (j);
}
