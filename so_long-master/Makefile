
SRC = training.


OBJS	= ${SRC:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIBMLX	= ./MLX42/build/libmlx42.a
LIBGLFW	= -lm -lglfw -L"/Users/${USER}/.brew/opt/glfw/lib/"
NAME	= so_long

.c.o	:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all		: 
	make setup
	make -C ./MLX42/build
	make so_long

so_long	: ${NAME}

setup	:
	$(shell mkdir MLX42/build &>/dev/null)
	$(shell cmake -S ./MLX42 -B ./MLX42/build &>/dev/null)
	@echo "setup complete"

rebuild	:
	@rm -rf ./MLX42/build
	@echo "rebuilding source..."
	make setup

basic	:
	@rm -rf ./MLX42/build

${NAME}	: ${OBJS}
	gcc ${OBJS} ${LIBMLX} ${LIBGLFW} ${CFLAGS} -o ${NAME}

clean	:
	rm -rf ${OBJS}
	make clean -C ./MLX42/build

fclean	: clean
	@make basic
	rm -rf ${NAME}

re		: fclean all

.PHONY	:	fclean clean re all