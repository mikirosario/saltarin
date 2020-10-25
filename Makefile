NAME = saltarin

SRC = main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBS = -I ./minilibx_linux/ -L ./minilibx_linux/ -lmlx_Linux -lm -lXext -lX11 -lbsd -g

$(NAME):
	make -C ./minilibx_linux/
	gcc $(FLAGS) $(SRC) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o
	rm -f ./minilibx_linux/*.o

fclean: clean
	rm -f $(NAME)
	rm -f ./minilibx_linux/*.a

.PHONY: all clean fclean