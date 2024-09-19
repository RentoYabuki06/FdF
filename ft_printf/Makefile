# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 14:59:44 by yabukirento       #+#    #+#              #
#    Updated: 2024/05/03 15:36:46 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_itoa.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_format.c \
		ft_printf.c \
		ft_print_percent.c \
		ft_printptr.c \
		ft_printnbr.c \
		ft_print_hex.c \
		ft_print_unsigned.c \
		ft_strdup.c
		

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all