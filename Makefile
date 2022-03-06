NAME = our_cub3D

SRC = parcer/cub.c \
      parcer/ft_check_map.c \
      parcer/ft_check_map_utils.c \
      parcer/ft_cub_utils.c \
      parcer/ft_exit_cube.c \
      parcer/ft_read_file.c \
      parcer/ft_libft_functions.c \
      get_next_line/get_next_line.c \
      get_next_line/get_next_line_utils.c \
      source/raycasting.c \
      source/raycating_steps.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		mv mlx/libmlx.a .
		#gcc -Wall -g -Werror -Wextra -c $(SRC)
		gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
		make -C mlx clean
		rm -rf $(OBJ) libmlx.a

fclean: clean
		make -C mlx clean
		rm -rf $(NAME)

re : fclean all