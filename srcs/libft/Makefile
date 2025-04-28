SRCS_DIR = srcs
INCLUDES_DIR = includes
OBJ_DIR = obj

SRCS_CONV = $(SRCS_DIR)/conversion/ft_atoi.c \
			$(SRCS_DIR)/conversion/ft_atol.c \
			$(SRCS_DIR)/conversion/ft_itoa.c \
			$(SRCS_DIR)/conversion/ft_tolower.c \
			$(SRCS_DIR)/conversion/ft_toupper.c

SRCS_COND =	$(SRCS_DIR)/conditional/ft_isalnum.c \
			$(SRCS_DIR)/conditional/ft_isalpha.c \
			$(SRCS_DIR)/conditional/ft_isascii.c \
			$(SRCS_DIR)/conditional/ft_isdigit.c \
			$(SRCS_DIR)/conditional/ft_isprint.c

SRCS_MEM = 	$(SRCS_DIR)/memory/ft_bzero.c \
			$(SRCS_DIR)/memory/ft_calloc.c \
			$(SRCS_DIR)/memory/ft_memchr.c \
			$(SRCS_DIR)/memory/ft_memcmp.c \
			$(SRCS_DIR)/memory/ft_memcpy.c \
			$(SRCS_DIR)/memory/ft_memmove.c \
			$(SRCS_DIR)/memory/ft_memset.c

SRCS_PUT =	$(SRCS_DIR)/put_fd/ft_fprintf.c \
			$(SRCS_DIR)/put_fd/ft_putchar_fd.c \
			$(SRCS_DIR)/put_fd/ft_putendl_fd.c \
			$(SRCS_DIR)/put_fd/ft_putnbr_fd.c \
			$(SRCS_DIR)/put_fd/ft_putstr_fd.c

SRCS_STR = 	$(SRCS_DIR)/string/ft_split.c \
			$(SRCS_DIR)/string/ft_strchr.c \
			$(SRCS_DIR)/string/ft_strcmp.c \
			$(SRCS_DIR)/string/ft_strdup.c \
			$(SRCS_DIR)/string/ft_striteri.c \
			$(SRCS_DIR)/string/ft_strjoin.c \
			$(SRCS_DIR)/string/ft_strlcat.c \
			$(SRCS_DIR)/string/ft_strlcpy.c \
			$(SRCS_DIR)/string/ft_strlen.c \
			$(SRCS_DIR)/string/ft_strmapi.c \
			$(SRCS_DIR)/string/ft_strncmp.c \
			$(SRCS_DIR)/string/ft_strndup.c \
			$(SRCS_DIR)/string/ft_strnstr.c \
			$(SRCS_DIR)/string/ft_strrchr.c \
			$(SRCS_DIR)/string/ft_strtrim.c \
			$(SRCS_DIR)/string/ft_substr.c

SRCS = $(SRCS_CONV) $(SRCS_COND) $(SRCS_MEM) $(SRCS_PUT) $(SRCS_STR)

SRCS_BONUS = 	$(SRCS_DIR)/list/ft_lstadd_back.c \
				$(SRCS_DIR)/list/ft_lstadd_front.c \
				$(SRCS_DIR)/list/ft_lstclear.c \
				$(SRCS_DIR)/list/ft_lstdelone.c \
				$(SRCS_DIR)/list/ft_lstiter.c \
				$(SRCS_DIR)/list/ft_lstlast.c \
				$(SRCS_DIR)/list/ft_lstmap.c \
				$(SRCS_DIR)/list/ft_lstnew.c \
				$(SRCS_DIR)/list/ft_lstsize.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR)

NAME = libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)
	touch bonus

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) bonus

re: fclean all
