/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:54:53 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/08 16:34:02 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

t_cub	*read_map_file_util(int k, int fd, t_cub *cub)
{
	int		i;
	char	*line;
	int		count;

	i = 0;
	while (k)
	{
		k = get_next_line(fd, &line);
		if (k == -1)
			exit_cube_file(6);
		cub->map[i] = ft_strdup(line);
		if (!(cub->map[i][0] == ' ' || cub->map[i][0] == '1'))
			count = count + ft_check_before_map(cub->map[i]);
		else if (cub->map[i][0] == ' ' || cub->map[i][0] == '1')
			if (count < 6)
				exit_cube_card(9);
		i++;
		free(line);
	}
	cub->map[i] = NULL;
	return (cub);
}

t_cub	read_map_card_util(t_cub *cub, t_cub map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub->str_num)
	{
		if (((cub->map[i][0] == ' ' && (cub->map[i][1] == ' '
				|| cub->map[i][1] == '1')) || cub->map[i][0] == '1')
				|| (cub->map[i][0] == '\0' && ((cub->map[i + 1][0] == ' '
				|| cub->map[i + 1][0] == '1') && (cub->map[i - 1][0] == ' '
				|| cub->map[i - 1][0] == '1'))))
		{
			map.map[j] = cub->map[i];
			j++;
		}
		i++;
	}
	map.map[j] = NULL;
	return (map);
}

t_cub	check_player_position_util(t_cub *cub, t_cub map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (ft_str_char(CHECK, map.map[i][j]))
			{
				if (map.map[i][j] == 'N' || map.map[i][j] == 'S')
					count = count + player_position_n_s(cub, map, i, j);
				else if (map.map[i][j] == 'W' || map.map[i][j] == 'E')
					count = count + player_position_w_e(cub, map, i, j);
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_cube_card_util(1);
	return (map);
}

int	player_position_n_s(t_cub *cub, t_cub map, int i, int j)
{
	int	count;

	count = 0;
	if (map.map[i][j] == 'N')
	{
		cub->map_N = 1;
		cub->drop.x = j;
		cub->drop.y = i;
		count++;
		map.map[i][j] = '0';
	}
	else if (map.map[i][j] == 'S')
	{
		cub->map_S = 1;
		cub->drop.x = j;
		cub->drop.y = i;
		count++;
		map.map[i][j] = '0';
	}
	return (count);
}

int	player_position_w_e(t_cub *cub, t_cub map, int i, int j)
{
	int	count;

	count = 0;
	if (map.map[i][j] == 'E')
	{
		cub->map_E = 1;
		cub->drop.x = j;
		cub->drop.y = i;
		count++;
		map.map[i][j] = '0';
	}
	else if (map.map[i][j] == 'W')
	{
		cub->map_W = 1;
		cub->drop.x = j;
		cub->drop.y = i;
		count++;
		map.map[i][j] = '0';
	}
	return (count);
}
