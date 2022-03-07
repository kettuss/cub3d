/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_the_third_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:57:51 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/07 23:32:30 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

void	record_player_dir(t_cub **cub, char c)
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

void	init_player_dir(t_cub **cub, char c)
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
	record_player_dir(cub, c);
}

static int	is_player(char c, t_cub **cub, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		init_player_dir(cub, c);
		(*cub)->lodev.pos_x = y + 0.5;
		(*cub)->lodev.pos_y = x + 0.5;
		(*cub)->map[y][x] = '0';
		return (1);
	}
	return (0);
}

void	init_player(t_cub *cub)
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
			if (is_player(map[y][x], &cub, x, y))
				break ;
			x++;
		}
		y++;
	}
}

void	print_all(t_cub *cub, int x, t_lodev *all)
{
	int	i;

	i = 0;
	while (i < all->draw_start)
	{
		my_mlx_pixel_put(cub->window, x, i, cub->color_f);
		i++;
	}
	i = print_texture(cub, all, i, x);
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(cub->window, x, i, cub->color_c);
		i++;
	}
}
