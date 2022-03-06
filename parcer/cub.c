/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:02 by ikathrin          #+#    #+#             */
/*   Updated: 2022/03/06 18:50:09 by ikathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3D.h"

int main(int argc, char **argv) {
    t_cub cub;

    if (argc < 2)
        exit_cube(4);
    else if (argc > 2)
        exit_cube(5);
    read_map_file(argv, &cub);
    checker_map(&cub, argv);
}
