# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:33:10 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/19 16:42:49 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c			\
		./srcs/init.c			\
		./srcs/init_check.c		\
		./srcs/ft_read_map.c	\
		./srcs/ft_hextoi.c		\
		./srcs/ft_conv_iso.c		\
		./srcs/ft_draw_line.c		\

OBJS = $(SRCS:.c=.o)

GET_NEXT_LINE_DIR = ./get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF) 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(GET_NEXT_LINE) $(FT_PRINTF)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(MAKE) -C $(FT_PRINTF) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
