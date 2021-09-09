NAME = so_long

CC = clang
FLAGS = -g -Wall -Wextra -Werror
FLAGS_TESTE = -g -Wall -Wextra
MLX_FLAGS = -lmlx -lXext -lX11
SANITIZE = -fsanitize=leak

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
		$(SRC_DIR)/game_utils.c\
		$(SRC_DIR)/game_map_erros.c\
		$(SRC_DIR)/game_animation.c

BONUS_SRC_DIR = srcs_bonus
BONUS_SRC = $(BONUS_SRC_DIR)/main_bonus.c\
		$(BONUS_SRC_DIR)/game_map_bonus.c\
		$(BONUS_SRC_DIR)/game_start_bonus.c\
		$(BONUS_SRC_DIR)/game_display_bonus.c\
		$(BONUS_SRC_DIR)/game_init_imgs_bonus.c\
		$(BONUS_SRC_DIR)/game_movement_bonus.c\
		$(BONUS_SRC_DIR)/game_utils_bonus.c\
		$(BONUS_SRC_DIR)/game_map_erros_bonus.c\
		$(BONUS_SRC_DIR)/game_animation_bonus.c\
		$(BONUS_SRC_DIR)/game_enemy_bonus.c\
		$(BONUS_SRC_DIR)/game_print_moves_bonus.c

		
INCLUDE_DIR = includes
INCLUDE = includes/so_long.h
BONUS_INCLUDE = includes/so_long_bonus.h

OBJ_DIR= obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ_DIR = bonus_obj
BONUS_OBJ = $(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) -lm $(OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) $(SANITIZE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS_TESTE) -I$(INCLUDE_DIR) -o $@ $<

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_INCLUDE)
	mkdir -p $(BONUS_OBJ_DIR)
	$(CC) -c $(FLAGS_TESTE) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

bonus: $(LIBFT) $(MLX) $(BONUS_OBJ)
	$(CC) -lm $(BONUS_OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) $(SANITIZE) -o $(NAME)

run: all
	./$(NAME)

clean:
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
