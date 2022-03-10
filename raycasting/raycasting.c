/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:35:16 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/10 21:29:51 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub_3D.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)(data->addr + (y * data->line_l + x * (data->bpp / 8)));
	*(unsigned int *)dst = color;
}

unsigned int	color_pixel_texture(t_vars *img, int i, int j)
{
	char			*adr;
	unsigned int	color;

	adr = (char *)(img->addr + (j * img->line_l + i * (img->bpp / 8)));
	color = *(unsigned int *)adr;
	return (color);
}

void static	get_color_texure(t_cub *cub, int ***color, char *way)
{
	int		w;
	int		h;
	int		i;
	int		j;
	t_vars	img;

	i = -1;
	//way = "image/brick1.xpm";
    // way = cub->map_ea;
	img.img = mlx_xpm_file_to_image(cub->window->mlx, way, &w, &h);
	if (!img.img)
		exit_cube_file(7);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.en);
	(*color) = (int **) malloc(sizeof(int *) * w);
	if (!(*color))
		exit_cube_file(7);
	while (++i < TEX_WIDTH)
	{
		j = -1;
		(*color)[i] = (int *)malloc(sizeof(int) * h);
		while (++j < TEX_HEIGHT)
			(*color)[i][j] = color_pixel_texture(&img, i, j);
	}
}

void	init_texture(t_cub *cub)
{
	get_color_texure(cub, &cub->nor, cub->map_no);
	get_color_texure(cub, &cub->sou, cub->map_so);
	get_color_texure(cub, &cub->wes, cub->map_we);
	get_color_texure(cub, &cub->eas, cub->map_ea);
}

int	print_texture(t_cub *cub, t_lodev *all, int i, int x)
{
	int	color;
	int	tex_y;

	while (i <= all->draw_end)
	{
		tex_y = (int) cub->lodev.tex_pos & (TEX_HEIGHT - 1);
		cub->lodev.tex_pos += cub->lodev.step;
		if (all->side == 1)
		{
			if (all->step_y == -1)
				color = cub->wes[cub->lodev.tex_x][tex_y];
			else
				color = cub->eas[cub->lodev.tex_x][tex_y];
		}
		else
		{
			if (all->step_x == -1)
				color = cub->nor[cub->lodev.tex_x][tex_y];
			else
				color = cub->sou[cub->lodev.tex_x][tex_y];
		}
		my_mlx_pixel_put(cub->window, x, i, color);
		i++;
	}
	return (i);
}
