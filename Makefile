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

all: $(NAME)

$(NAME): dir $(OBJ)
	$(CC) $(FLAGS) $(OBJ) libft.a -I $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -I $(INCLUDE) -o $@

dir:
	mkdir $(OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)