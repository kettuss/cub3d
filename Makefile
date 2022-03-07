NAME = our_cub3D

SRC = parcer/cub.c \
      parcer/ft_check_map.c \
      parcer/ft_check_map_utils.c \
      parcer/ft_check_map_utils_2.c \
      parcer/ft_cub_utils.c \
      parcer/ft_read_file_utils.c \
      parcer/ft_exit_cube.c \
      parcer/ft_read_file.c \
      parcer/ft_libft_functions_2.c \
      parcer/ft_libft_functions.c \
      get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c \
      raycasting/init_lodev.c \
      raycasting/image.c \
      raycasting/keycode.c \
      raycasting/map_fill_image.c \
      raycasting/point.c \
      raycasting/raycasting_second_part.c \
      raycasting/raycasting_the_third_part.c \
      raycasting/raycasting.c

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework Opengl -framework Appkit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(MAKE) -C mlx
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean:
		make -C mlx clean
		rm -rf $(OBJ) libmlx.a

fclean: clean
		make -C mlx clean
		rm -rf $(NAME)

re : fclean all