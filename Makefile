CC      = cc
NAME    = fractol
OBJ     = $(SRC:.c=.o)
MLX     = MacroLibX
HEADER  = fractol.h
SRC     =	\
fractol.c	\
utils.c		\
events.c	\
mandelbrot.c\
julia.c		\
more_events.c\

CFLAGS  = -Werror -Wall -Wextra -g -I$(MLX)/includes
LIBS    = $(MLX)/libmlx.so -lSDL2 -lm

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C $(MLX)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)

re: fclean all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

.PHONY: all re clean fclean
