# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smurayam <smurayam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 21:54:49 by nnnya             #+#    #+#              #
#    Updated: 2026/01/20 20:22:22 by smurayam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# パス設定 (提供されたファイル構成に基づく)
MLX_PATH    = includes/minilibx-linux
MLX_LIB     = $(MLX_PATH)/libmlx.a
LIBFT_PATH  = includes/Libft01
LIBFT_LIB   = $(LIBFT_PATH)/libft.a

# ソースファイル (分割した場合)
SRCS        = main.c events.c render.c
OBJS        = $(SRCS:.c=.o)

# リンクフラグ
# -Lでライブラリの場所を指定し、-lでライブラリ名を指定 (libft.a -> -lft)
LDFLAGS     = -L$(MLX_PATH) -lmlx -L$(LIBFT_PATH) -lft -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# Libftのコンパイル
$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

# MinilibXのコンパイル
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