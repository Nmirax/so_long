#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      printf/libft/ft_memcpy.c \
                          printf/libft/ft_lstmap_bonus.c \
                          printf/libft/ft_strchr.c \
                          printf/libft/ft_calloc.c \
                          printf/libft/ft_split.c \
                          printf/libft/ft_lstdelone_bonus.c \
                          printf/libft/ft_isdigit.c \
                          printf/libft/ft_isalpha.c \
                          printf/libft/ft_lstiter_bonus.c \
                          printf/libft/ft_putnbr_fd.c \
                          printf/libft/ft_putendl_fd.c \
                          printf/libft/ft_isascii.c \
                          printf/libft/ft_memcmp.c \
                          printf/libft/ft_strrchr.c \
                          printf/libft/ft_isalnum.c \
                          printf/libft/ft_bzero.c \
                          printf/libft/ft_substr.c \
                          printf/libft/ft_strlen.c \
                          printf/libft/ft_lstadd_back_bonus.c \
                          printf/libft/ft_strtrim.c \
                          printf/libft/ft_strlcat.c \
                          printf/libft/ft_lstclear_bonus.c \
                          printf/libft/ft_isprint.c \
                          printf/libft/ft_tolower.c \
                          printf/libft/ft_strdup.c \
                          printf/libft/ft_atoi.c \
                          printf/libft/ft_lstadd_front_bonus.c \
                          printf/libft/ft_memchr.c \
                          printf/libft/ft_strlcpy.c \
                          printf/libft/ft_putchar_fd.c \
                          printf/libft/ft_lstlast_bonus.c \
                          printf/libft/ft_toupper.c \
                          printf/libft/ft_itoa.c \
                          printf/libft/ft_strmapi.c \
                          printf/libft/ft_strncmp.c \
                          printf/libft/ft_memmove.c \
                          printf/libft/ft_lstsize_bonus.c \
                          printf/libft/ft_lstnew_bonus.c \
                          printf/libft/ft_strjoin.c \
                          printf/libft/ft_striteri.c \
                          printf/libft/ft_putstr_fd.c \
                          printf/libft/ft_memset.c \
                          printf/libft/ft_strnstr.c \
                          printf/src/ft_printf.c \
                          printf/src/ft_printchar.c \
                          printf/src/ft_printptr.c \
                          printf/src/ft_itoa_base.c \
                          printf/src/ft_printpercent.c \
                          printf/src/ft_printint.c \
                          printf/src/ft_decimal_itoa.c \
                          printf/src/ft_printstr.c \
                          printf/src/ft_printhex.c \
                          src/so_long_position.c \
                          src/memory.c \
                          src/textures.c \
                          src/so_long_condition.c \
                          src/so_long.c \
                          src/read_map.c \
                          src/hook.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


# CLR_RMV := \033[0m
# RED := \033[1;31m
# GREEN := \033[1;32m
# YELLOW := \033[1;33m
# BLUE := \033[1;34m
# CYAN := \033[1;36m
# RM := rm -f

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@$(MAKE) -C MLX42/build all >/dev/null 2>&1
	@cp ./MLX42/build/libmlx42.a .
	$(CC) $(FLAGS) -g3 -Ofast -o $(NAME) -IMLX42 -Imlx $(OBJS) -LMLX42/build -lmlx42 -framework OpenGL -framework AppKit
	@echo "$(GREEN)$(NAME) created ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): $(OBJS)
	@echo "$(GREEN)Linux compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	@$(MAKE) -C MLX42/build all
	$(CC) $(FLAGS) -g3 -o $(NAME) $(OBJS) -IMLX42 -Imlx -LMLX42/build -lmlx42 -lXext -lX11 -lglfw -lm
	@echo "$(GREEN)$(NAME) created ✔️"
endif

all: $(NAME)

ifeq ($(UNAME), Darwin)
clean:
	@$(RM) *.o */*.o */*/*.o
	@rm -rf $(NAME).dSYM >/dev/null 2>&1
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
	@$(RM) *.o */*.o */*/*.o
	@rm -rf $(NAME).dSYM >/dev/null 2>&1
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C MLX42/build clean
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean: clean
	@$(RM) $(NAME)
	@rm libmlx42.a
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re: fclean all

.PHONY: all clean fclean re