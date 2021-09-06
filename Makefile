NAME = so_long

CC = clang
FLAGS = -g -Wall -Wextra -Werror
FLAGS_TESTE = -g -Wall -Wextra
MLX_FLAGS = -lmlx -lXext -lX11

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

MLX_DIR = mlx_linux
MLX = mlx_linux/libmlx.a

SRC_DIR = srcs
SRC = $(SRC_DIR)/main.c\
		$(SRC_DIR)/game_map.c\
		$(SRC_DIR)/game_start.c\
		$(SRC_DIR)/game_display.c\
		$(SRC_DIR)/game_init_imgs.c\
		$(SRC_DIR)/game_movement.c\
		$(SRC_DIR)/game_utils.c

INCLUDE_DIR = includes
INCLUDE = includes/so_long.h

OBJ_DIR= obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) -lm $(OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS_TESTE) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

run: all
	./$(NAME)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
