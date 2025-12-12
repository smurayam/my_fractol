# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smurayam <smurayam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/24 22:45:01 by smurayam          #+#    #+#              #
#    Updated: 2024/11/28 05:59:13 by smurayam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

#r: Add or replace object files in the archive.
#c: Create the archive if it doesn’t already exist.
#s: Create an index of symbols to speed up linking.
ARS = ar rcs

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

BONUS_FLAG = .bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(ARS) $(NAME) $(OBJS)

bonus: $(BONUS_FLAG)

$(BONUS_FLAG) : $(BONUS_OBJS)
	$(ARS) $(NAME) $(BONUS_OBJS)
	@touch $(BONUS_FLAG)

# Compile each .c file into its corresponding .o file.
# %: matches any string (used for pattern matching).
# $<: the first dependency (source .c file).
# $@: the target file (.o file to be created).
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(BONUS_FLAG)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all bonus clean fclean re