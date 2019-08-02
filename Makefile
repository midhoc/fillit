NAME = fillit

SRC = ./fillit.c \
	./board.c \
	./back_track.c \
	./get_file.c \
	./normalise.c

OBJ = $(SRC:.c=.o)

HEADER = ./fillit.h

INCLUDE_PATH = ./

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): %.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDE_PATH)

$(LIBFT):
	make -C ./libft/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
