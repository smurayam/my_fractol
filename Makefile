# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 21:54:49 by nnnya             #+#    #+#              #
#    Updated: 2026/01/20 20:25:17 by smurayam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

MLX_PATH    = includes/minilibx-linux
MLX_LIB     = $(MLX_PATH)/libmlx.a
LIBFT_PATH  = includes/Libft
LIBFT_LIB   = $(LIBFT_PATH)/libft.a

SRCS        = main.c events.c render.c
OBJS        = $(SRCS:.c=.o)

LDFLAGS     = -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re