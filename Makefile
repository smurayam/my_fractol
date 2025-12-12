# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnnya <nnnya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 15:48:51 by nnnya             #+#    #+#              #
#    Updated: 2025/12/12 15:59:37 by nnnya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re