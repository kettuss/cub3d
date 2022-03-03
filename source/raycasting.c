/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:56:39 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/03 21:27:16 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_3D.h"

void	ft_record_player(t_cub **cub, char c)
{
	if (c == 'E')
	{
		(*cub)->lodev.dir_x = 0;
		(*cub)->lodev.dir_y = 1;
		(*cub)->lodev.plane_y = 0;
		(*cub)->lodev.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		(*cub)->lodev.dir_x = 0;
		(*cub)->lodev.dir_y = -1;
		(*cub)->lodev.plane_y = 0;
		(*cub)->lodev.plane_x = -0.66;
	}
}

void	ft_player_dir(t_cub **cub, char c)
{
	if (c == 'N')
	{
		(*cub)->lodev.dir_x = -1;
		(*cub)->lodev.dir_y = 0;
		(*cub)->lodev.plane_y = 0.66;
		(*cub)->lodev.plane_x = 0;
	}
	else if (c == 'S')
	{
		(*cub)->lodev.dir_x = 1;
		(*cub)->lodev.dir_y = 0;
		(*cub)->lodev.plane_y = -0.66;
		(*cub)->lodev.plane_x = 0;
	}
	ft_record_player(cub, c);
}

static int	ft_player(char c, t_cub **cub, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		ft_player_dir(cub, c);
		(*cub)->lodev.pos_x = y + 0.5;
		(*cub)->lodev.pos_y = x + 0.5;
		(*cub)->map[y][x] = '0';
		return (1);
	}
	return (0);
}

void	ft_init_player(t_cub *cub)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = cub->map;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_player(map[y][x], &cub, x, y))
				break ;
			x++;
		}
		y++;
	}
}
//init player