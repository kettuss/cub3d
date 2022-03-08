/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:02 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/08 15:43:44 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int	keycode(int keycode, t_cub **cub)
{
	char	**map;
	double	move_speed;
	double	old_dir_x;
	double	old_plane_x;

	map = (*cub)->map;
	move_speed = 0.11;
	old_dir_x = (*cub)->lodev.dir_x;
	old_plane_x = (*cub)->lodev.plane_x;
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_W)
		key_w(cub, map, move_speed);
	if (keycode == KEY_S)
		key_s(cub, map, move_speed);
	if (keycode == KEY_D)
		key_d(cub, map, move_speed);
	if (keycode == KEY_A)
		key_a(cub, map, move_speed);
	else if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		key_rl(cub, old_dir_x, old_plane_x, keycode);
	return (0);
}

int	close_all(t_cub *cub)
{
	(void)cub;
	exit(0);
	return (0);
}

void	raycasting(t_cub *cub)
{
	init_player(cub);
	cub->window = (t_vars *)malloc(sizeof(t_vars));
	cub->window->mlx = mlx_init();
	cub->window->win = mlx_new_window(cub->window->mlx, WIDTH, HEIGHT,
			"cub3D\n");
	cub->window->img = mlx_new_image(cub->window->mlx, WIDTH, HEIGHT);
	cub->window->addr = mlx_get_data_addr(cub->window->img,
			&cub->window->bpp, &cub->window->line_l, &cub->window->en);
	cub->window->size_img.y = HEIGHT;
	cub->window->size_img.x = WIDTH;
	init_texture(cub);
	mlx_loop_hook(cub->window->mlx, (void *)pechat, cub);
	mlx_hook(cub->window->win, 2, 1L << 0, keycode, &cub);
	mlx_hook(cub->window->win, 17, 1L << 2, close_all, &cub);
	mlx_loop(cub->window->mlx);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc < 2)
		exit_cube_file(4);
	else if (argc > 2)
		exit_cube_file(5);
	read_map_file(argv, &cub);
	checker_map(&cub, argv);
	if (cub.map_N == 1)
		cub.map[cub.drop.y][cub.drop.x] = 'N';
	else if (cub.map_S == 1)
		cub.map[cub.drop.y][cub.drop.x] = 'S';
	else if (cub.map_E == 1)
		cub.map[cub.drop.y][cub.drop.x] = 'E';
	else if (cub.map_W == 1)
		cub.map[cub.drop.y][cub.drop.x] = 'W';
	raycasting(&cub);
}
