SRC_DIR = ./src
LIBFT_DIR = ./pipex_libft
OBJ_DIR = ./obj
INCLUDE = ./includes
NAME = pipex

SRC = \
	$(SRC_DIR)/process.c \
	$(SRC_DIR)/pipex.c \
	$(SRC_DIR)/split.c \
	$(SRC_DIR)/error.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_memset.c \
	$(LIBFT_DIR)/ft_strlcpy.c 

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror
CC = cc

all: dir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -I $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -I $(INCLUDE) -o $@

dir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all dir clean fclean re