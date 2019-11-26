NAME = fractol
CC = gcc


SRC = fractal_zoom.c main.c mouse_move.c fractol.c julia.c usage.c
OBJ = fractal_zoom.o main.o mouse_move.o fractol.o julia.o usage.o

MINILIBX_FLAG = -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c fractol.h
	$(CC) -c $(CFLAGS) $< -o $@ 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(MINILIBX_FLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
