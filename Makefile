SRC_DIR = ./src

SRC = \
	$(SRC_DIR)/pipex.c \
	$(SRC_DIR)/process.c \
	$(SRC_DIR)/check.c \
	$(SRC_DIR)/libft.c


all:
	gcc $(SRC) -I ./includes -o pipex
