/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:54:53 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/11 00:11:01 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int	ft_str_len(t_cub *cub)
{
	int	j;

	j = 0;
	cub->str_col = 0;
	while (cub->map[0][j])
	{
		cub->str_col++;
		j++;
	}
	return (cub->str_col);
}

char	*ft_str_char(const char *s, char c)
{
	int	i;

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

void	ft_str_number(t_cub *cub, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_cube_file(6);
	cub->str_num = 1;
	while (get_next_line(fd, &line))
	{
		cub->str_num++;
		free(line);
	}
	free(line);
    free(cub->map);
    close(fd); //TODO
}

void	read_map_file(char **argv, t_cub *cub)
{
	int		k;
	int		fd;

	k = 1;
	ft_str_number(cub, argv);
	cub->map = (char **)malloc(sizeof(char *) * (cub->str_num + 2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_cube_file(6);
	cub = read_map_file_util(k, fd, cub);
	read_map_card(cub, argv);
}

void	read_map_card(t_cub *cub, char **argv)
{
	int		i;
	t_cub	map;

	map.map = (char **)malloc(sizeof(char *) * (cub->str_num + 2));
	map = read_map_card_util(cub, map);
	i = 0;
	while (map.map[i] != NULL)
	{
		if (map.map[i][0] == '\0')
			exit_cube_card_util(1);
		i++;
	}
	map = check_player_position_util(cub, map);
	checker_map(cub, argv);
	copy_to_cub(cub, map);
	free(map.map);
}
