/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeanuts <kpeanuts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:07:42 by kpeanuts          #+#    #+#             */
/*   Updated: 2022/03/10 21:31:06 by kpeanuts         ###   ########.fr       */
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
# define ESC 53

# define HEIGHT 1080
# define WIDTH 1920

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define TURN 0.05
# define ROTSPEED 0.055

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

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_vars 
{
    void    *mlx;
    void    *win;
    void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		en;
	t_point	size_img;
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

typedef struct s_rgb
{
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		f;
	int		c;
}t_rgb;

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
    int **nor;
    int **sou;
    int **wes;
    int **eas;
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
   
    struct s_rgb    *rgb;
    t_xy_system  drop;
    t_picture figure;
    t_vars *window;
    t_vars img_map;

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


//char	*ft_utils_for_no_and_so(t_cub *cub, int i, int j);
void ft_utils_for_no_and_so(t_cub *cub, int i, int j);



void ft_utils_for_we_and_ea(t_cub *cub, int i, int j);
int ft_check_before_map(char *cub);
//void read_map_card(t_cub *cub);
void read_map_card(t_cub *cub, char **argv);
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
int player_position_n_s(t_cub *cub, t_cub map, int i, int j);
int player_position_w_e(t_cub *cub, t_cub map, int i, int j);
void copy_to_cub(t_cub *cub, t_cub map);

int	ft_count(char const *s, char c);
int	ft_lgthword(char const *s, char c, int k);
char	**ft_clean(char **str, int n);
char	**ft_fillnewstr(char const *s, int n, char c, char **str);
char	**ft_split(char const *s, char c);

long ft_color_parse_to_int(char *cub);
void ft_utils_for_colors(t_cub *cub, int i, int j, int k);

//void    exit_cube_card(int i);
//void    exit_cube_file(int i);
void    init_player(t_cub *cub);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int	print_texture(t_cub *cub, t_lodev *all, int i, int x);
void	init_lodev(t_lodev *all);
void	*pechat(t_cub *cub);
void	key_w(t_cub **cub, char **map, double moveSpeed);
void	key_s(t_cub **cub, char **map, double moveSpeed);
void	key_d(t_cub **cub, char **map, double moveSpeed);
void	key_rl(t_cub **cub, double olddir_x, double oldplane_x, int keycode);
void	key_a(t_cub **cub, char **map, double moveSpeed);
void	init_texture(t_cub *cub);
void	print_all(t_cub *cub, int x, t_lodev *all);
t_point	point_set(int x, int y);

#endif