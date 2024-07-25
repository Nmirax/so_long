# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 11:26:34 by abakhaev          #+#    #+#              #
#    Updated: 2024/07/25 12:27:32 by abakhaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
CC        := cc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      ft_substr.c \
                          ft_calloc.c \
                          ft_putendl_fd.c \
                          ft_bzero.c \
                          ft_strncmp.c \
                          ft_isprint.c \
                          ft_putnbr_fd.c \
                          ft_isdigit.c \
                          ft_isascii.c \
                          ft_memcmp.c \
                          ft_putstr_fd.c \
                          ft_strlcat.c \
                          ft_strlen.c \
                          ft_strnstr.c \
                          ft_strjoin.c \
                          ft_memcpy.c \
                          ft_isalnum.c \
                          ft_toupper.c \
                          ft_memset.c \
                          ft_atoi.c \
                          ft_strlcpy.c \
                          ft_strdup.c \
                          ft_memmove.c \
                          ft_putchar_fd.c \
                          ft_isalpha.c \
                          ft_strchr.c \
                          ft_strrchr.c \
                          ft_memchr.c \
                          ft_tolower.c \
						  ft_strtrim.c \
						  ft_striteri.c \
						  ft_strmapi.c \
						  ft_itoa.c \
						  ft_split.c


SRC_BONUS := 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
                          
OBJS        := $(SRCS:.c=.o)

OBJS_BONUS := $(SRC_BONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"


all:		${NAME}

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "Done!"


clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "Deleting objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "Deleting binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re