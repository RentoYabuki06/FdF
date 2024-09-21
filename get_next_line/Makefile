# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:47:11 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/21 10:35:16 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	get_next_line.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(OBJS)
			ar rc $@ $^
			ranlib $@

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re