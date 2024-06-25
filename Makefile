# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahri <itahri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 13:12:50 by itahri            #+#    #+#              #
#    Updated: 2024/06/25 16:11:59 by itahri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

SRCS = $(addprefix srcs/,  main.c map_parsing.c)

INCLUDES = ./includes -I ./libft/includes/

LIBFT = libft.a
LIB_DIR = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINI_LIBX = libmlx.a
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

all : $(MINI_LIBX) $(LIBFT) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $< -o $@ 

$(LIBFT):
	make -C ./libft

$(MINI_LIBX) :
	make -C $(MINI_LIBX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES)  $(OBJS) -o $(NAME) -L$(LIB_DIR) -lft 

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re