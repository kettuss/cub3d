/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:34:51 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/07 23:34:52 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub_3D.h"

void	key_w(t_cub **cub, char **map, double moveSpeed)
{
	if ((map[(int)((*cub)->lodev.pos_x + (*cub)->lodev.dir_x
				* moveSpeed * 1.2)][(int)(*cub)->lodev.pos_y]) == '0')
	(*cub)->lodev.pos_x += (*cub)->lodev.dir_x * moveSpeed;
	if (map[(int)(*cub)->lodev.pos_x][(int)((*cub)->lodev.pos_y
		+ (*cub)->lodev.dir_y * moveSpeed * 1.2)] == '0')
	(*cub)->lodev.pos_y += (*cub)->lodev.dir_y * moveSpeed;
}

void	key_s(t_cub **cub, char **map, double moveSpeed)
{
	if (map[(int)((*cub)->lodev.pos_x - (*cub)->lodev.dir_x
			* moveSpeed * 1.2)][(int)(*cub)->lodev.pos_y] == '0')
	(*cub)->lodev.pos_x -= (*cub)->lodev.dir_x * moveSpeed;
	if (map[(int)((*cub)->lodev.pos_x)][(int)((*cub)->lodev.pos_y
		- (*cub)->lodev.dir_y * moveSpeed * 1.2)] == '0')
	(*cub)->lodev.pos_y -= (*cub)->lodev.dir_y * moveSpeed;
}

void	key_d(t_cub **cub, char **map, double moveSpeed)
{
	if (map[(int)((*cub)->lodev.pos_x + (*cub)->lodev.dir_y
			* moveSpeed * 1.2)][(int)((*cub)->lodev.pos_y)] == '0')
		(*cub)->lodev.pos_x += (*cub)->lodev.dir_y * moveSpeed;
	if (map[(int)((*cub)->lodev.pos_x)][(int)((*cub)->lodev.pos_y
			- (*cub)->lodev.dir_x * moveSpeed * 1.2)] == '0')
		(*cub)->lodev.pos_y -= (*cub)->lodev.dir_x * moveSpeed;
}

void	key_a(t_cub **cub, char **map, double moveSpeed)
{
	if ((map[(int)((*cub)->lodev.pos_x - (*cub)->lodev.dir_y
				* moveSpeed * 1.2)][(int)(*cub)->lodev.pos_y]) == '0')
		(*cub)->lodev.pos_x -= (*cub)->lodev.dir_y * moveSpeed;
	if (map[(int)(*cub)->lodev.pos_x][(int)((*cub)->lodev.pos_y
			+ (*cub)->lodev.dir_x * moveSpeed * 1.2)] == '0')
		(*cub)->lodev.pos_y += (*cub)->lodev.dir_x * moveSpeed;
}

void	key_rl(t_cub **cub, double olddir_x, double oldplane_x, int keycode)
{
	double	rotspeed;

	rotspeed = ROTSPEED;
	if (keycode == ARROW_RIGHT)
	{
		(*cub)->lodev.dir_x = (*cub)->lodev.dir_x * cos(-rotspeed)
			- (*cub)->lodev.dir_y * sin(-rotspeed);
		(*cub)->lodev.dir_y = olddir_x * sin(-rotspeed)
			+ (*cub)->lodev.dir_y * cos(-rotspeed);
		(*cub)->lodev.plane_x = (*cub)->lodev.plane_x
			* cos(-rotspeed) - (*cub)->lodev.plane_y * sin(-rotspeed);
		(*cub)->lodev.plane_y = oldplane_x * sin(-rotspeed)
			+ (*cub)->lodev.plane_y * cos(-rotspeed);
	}
	else if (keycode == ARROW_LEFT)
	{
		(*cub)->lodev.dir_x = (*cub)->lodev.dir_x * cos(rotspeed)
			- (*cub)->lodev.dir_y * sin(rotspeed);
		(*cub)->lodev.dir_y = olddir_x * sin(rotspeed)
			+ (*cub)->lodev.dir_y * cos(rotspeed);
		(*cub)->lodev.plane_x = (*cub)->lodev.plane_x * cos(rotspeed)
			- (*cub)->lodev.plane_y * sin(rotspeed);
		(*cub)->lodev.plane_y = oldplane_x * sin(rotspeed)
			+ (*cub)->lodev.plane_y * cos(rotspeed);
	}
}
