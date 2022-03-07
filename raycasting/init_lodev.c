/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lodev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:04:43 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/07 22:42:51 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

void	init_lodev(t_lodev *all)
{
	all->camera_x = 0;
	all->raydir_x = 0;
	all->raydir_y = 0;
	all->map_x = 0;
	all->map_y = 0;
	all->side_dist_x = 0;
	all->side_dist_y = 0;
	all->delta_dist_x = 0;
	all->delta_dist_y = 0;
	all->perp_wall_dist = 0;
	all->step_x = 0;
	all->step_y = 0;
	all->hit = 0;
	all->side = 0;
	all->line_height = 0;
	all->draw_start = 0;
	all->draw_end = 0;
	all->wall_x = 0;
	all->tex_x = 0;
	all->step = 0;
	all->tex_pos = 0;
}
