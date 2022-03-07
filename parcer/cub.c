/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:02 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/07 19:13:47 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int	main(int argc, char **argv)
{
	t_cub	cub;

	cub.map_f = NULL;
	cub.map_c = NULL;
	cub.map_no = NULL;
	cub.map_so = NULL;
	cub.map_we = NULL;
	cub.map_ea = NULL;
	if (argc < 2)
		exit_cube_file(4);
	else if (argc > 2)
		exit_cube_file(5);
	read_map_file(argv, &cub);
	checker_map(&cub, argv);
}
