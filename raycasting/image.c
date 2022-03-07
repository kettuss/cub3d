/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:34:43 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/07 23:34:44 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub_3D.h"

t_vars	image_create(int x, int y, void *mlx_ptr)
{
	t_vars	image;

	image.img = mlx_new_image(mlx_ptr, x, y);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, \
		&image.line_l, &image.en);
	image.mlx = mlx_ptr;
	image.win = NULL;
	image.size_img.x = x;
	image.size_img.y = y;
	return (image);
}

t_vars	*new_image_create(int x, int y, void *mlx_ptr)
{
	t_vars	*image;

	image = (t_vars *)malloc(sizeof(t_vars));
	if (!image)
		exit (1);
	image->img = mlx_new_image(mlx_ptr, x, y);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_l,
			&image->en);
	image->mlx = mlx_ptr;
	image->win = NULL;
	image->size_img.x = x;
	image->size_img.y = y;
	return (image);
}

// закрашиваю один пиксель на изображении
void	pixel_put(t_vars *img, t_point	p, unsigned int colour)
{
	char	*dst;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return ;
	dst = (char *) img->addr + ((p.y * img->line_l) + (p.x * (img->bpp / 8)));
	*(unsigned int *)dst = colour;
}

// Получаю пиксель из изображения
size_t	pixel_get(t_vars *img, t_point p)
{
	void			*dst;
	unsigned int	ret;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return (0xFF000000);
	dst = img->addr + ((p.y * img->line_l) + (p.x * (img->bpp / 8)));
	ret = *(unsigned int *)dst;
	return (ret);
}

void	image_to_image_cp(t_vars *dst, t_vars *src, t_point position)
{
	t_point	i;
	t_point	tmp;
	int		color;

	i.y = -1;
	i.x = -1;
	while (++i.y < src->size_img.y)
	{
		while (++i.x < src->size_img.x)
		{
			tmp.x = i.x + position.x;
			tmp.y = i.y + position.y;
			color = pixel_get(src, i);
			if (color == 0x0)
				continue ;
			pixel_put(dst, tmp, color);
		}
		i.x = -1;
	}
}
