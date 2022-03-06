//
// Created by Iraida Kathrine on 3/2/22.
//

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