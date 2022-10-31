SRC_DIR = ./src
OBJ_DIR = ./obj
INCLUDE = ./includes
NAME = pipex

SRC = \
	$(SRC_DIR)/process.c \
	$(SRC_DIR)/pipex.c \
	$(SRC_DIR)/check.c 

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror 
CC = cc

all: dir $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) libft.a -I $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -I $(INCLUDE) -o $@

dir:
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all dir clean fclean re