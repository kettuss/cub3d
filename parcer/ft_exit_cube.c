/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:54:08 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/08 16:41:09 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

void	exit_cube_card(int i)
{
	if (i == 8)
	{
		printf("%s\n", "Error");
		printf("%s\n", "The file is not available at the specified path");
	}
	if (i == 9)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Check file`s parameters before the map");
	}
	if (i == 10)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Check if you really have 3 colors in F and C");
	}
	if (i == 11)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Colors in F or C are outside the [0; 255] range");
	}
	exit(1);
}

void	exit_cube_file(int i)
{
	if (i == 4)
	{
		printf("%s\n", "Error");
		printf("%s\n", "You have not selected a file");
	}
	if (i == 5)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Too many arguments. Just choose one file!");
	}
	if (i == 6)
	{
		printf("%s\n", "Error");
		printf("%s\n", "OMG!! I can't read your file. Is it really okay?");
	}
	if (i == 7)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Unable to open file at specified path");
	}
	exit(1);
}

void	exit_cube_card_util(int i)
{
	if (i == 1)
	{
		printf("%s\n", "Error");
		printf("%s\n", "Your card is wrong");
	}
	exit(1);
}

void	check_colors_range(int *new_array)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (new_array[i] < 0 || new_array[i] > 255)
		{
			exit_cube_card(11);
			break ;
		}
		i++;
	}
}

void	copy_to_cub(t_cub *cub, t_cub map)
{
	int	i;

	i = 0;
	while (map.map[i] != NULL)
	{
		cub->map[i] = map.map[i];
		i++;
	}
	cub->map[i] = NULL;
    //printf("map.map_no = %s\n", map.map_no);
	cub->color_f = map.color_f;
	cub->color_c = map.color_c;
	//cub->map_no = map.map_no;
	//cub->map_so = map.map_so;
	//cub->map_ea = map.map_ea;
	//cub->map_we = map.map_we;
}
