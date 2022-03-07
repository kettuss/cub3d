/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:07:42 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/03 21:03:07 by kpeanuts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D_H
# define CUB_3D_H

# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define CHECK "NSEW"
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123

typedef struct s_lodev
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}				t_lodev;

typedef struct s_vars 
{
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct s_data 
{
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
    int map_N; //flag for player`s position
    int map_S; //flag for player`s position
    int map_E; //flag for player`s position
    int map_W; //flag for player`s position
    t_xy_system drop;
    t_picture figure;
    t_vars window;

	t_lodev lodev;
}               t_cub;

void    exit_cube_card(int i);
void    exit_cube_file(int i);
void exit_cube_card_util(int i);
void read_map_file(char **argv, t_cub *cub);
int    ft_str_len(t_cub *cub);
char    *ft_str_char(const char *s, char c);
void    ft_str_number(t_cub *cub, char **argv);
int    ft_strncmp(const char *s1, const char *s2, size_t n);
void ft_check_wall(t_cub *cub);
void ft_check_player_position(t_cub *cub);
int ft_check_file_extention(char **argv);
void checker_map(t_cub *cub, char **argv);
void ft_check_path_images(t_cub *cub);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup_main(const char *str);
size_t	ft_strlen_main(const char *str);

int ft_check_read_path(char *cub);
void ft_utils_for_no_and_so(t_cub *cub, int i, int j);
void ft_utils_for_we_and_ea(t_cub *cub, int i, int j);
int ft_check_before_map(char *cub);
void read_map_card(t_cub *cub);
int	ft_atoi(const char *s);
char	*ft_check_space_tab(char *line);
t_cub *read_map_file_util(int k, int fd, t_cub *cub);
t_cub read_map_card_util(t_cub *cub, t_cub	map);
t_cub check_player_position_util(t_cub *cub, t_cub	map);
int check_max_size_string(int max_size, t_cub *cub);
t_cub check_spaces_in_the_map(t_cub *cub, t_cub map, int max_size);
int check_strings_count_in_the_map(t_cub map);
void check_wall_utils(t_cub map);
int check_insaid_part_map(t_cub map, int i, int j);
void check_colors_range(int *new_array);

int	ft_count(char const *s, char c);
int	ft_lgthword(char const *s, char c, int k);
char	**ft_clean(char **str, int n);
char	**ft_fillnewstr(char const *s, int n, char c, char **str);
char	**ft_split(char const *s, char c);

long ft_color_parse_to_int(char *cub);
void ft_utils_for_colors(t_cub *cub, int i, int j, int k);

void	ft_init_player(t_cub *cub);

#endif