//
// Created by Iraida Kathrine on 3/2/22.
//

#ifndef CUB3D_CUB_H
#define CUB3D_CUB_H

//# include "./mlx/mlx.h"
# include "GNL/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <string.h>

# define CHECK "01NSEW"
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_vars {
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct s_xy_system
{
    int x;
    int y;
}           t_xy_system;

typedef struct s_picture
{
    void *wall;
    void *player;
    void *player_to_a;
    void *player_to_s;
    void *player_to_d;
    void *heart;
    void *enemy;
    void *door;
    void *road;
}       t_picture;

typedef struct s_cub
{
    char **map;

    //new
    char *map_no; //check NO path
    char *map_so; //check SO path
    char *map_we; //check WE path
    char *map_ea; //check EA path
    char *map_f; //check F colors
    char *map_c; //check C colors
    long color_f; //get color F after changes
    long color_c; //get color C after changes

    int height;
    int width;
    int str_num; //count of strings in the file
    int prey;
    int str_col;
    int step;
    int map_N;
    int map_S;
    int map_E;
    int map_W;
    t_xy_system drop;
    t_picture figure;
    t_vars window;
}               t_cub;

void    exit_cube(int i);
void read_map_file(char **argv, t_cub *cub);
int    ft_str_len(t_cub *cub);
char    *ft_str_char(const char *s, char c);
void    ft_str_number(t_cub *cub, char **argv);
int    ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_check_wall(t_cub *cub);
void ft_check_enter_thing_stop(t_cub *cub);
int ft_check_file_extention(char **argv);
void checker_map(t_cub *cub, char **argv);
void ft_check_path_images(t_cub *cub);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup_main(const char *str);
size_t	ft_strlen_main(const char *str);
int ft_check_read_path(char *cub);

#endif //CUB3D_CUB_H
