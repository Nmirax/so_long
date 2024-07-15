# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 11:05:47 by abakhaev          #+#    #+#              #
#    Updated: 2024/07/15 11:05:53 by abakhaev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX		:= ./MLX42
FTPRINTF	:= ./printf
GNL			:= ./get_next_line

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(GNL)/gnl.a $(FTPRINTF)/libftprintf.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

gnl:
	@$(MAKE) -C $(GNL)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) ftprintf gnl 
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) 

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(FTPRINTF) fclean
	


re: clean all

.PHONY: all, clean, fclean, re, libmlx
