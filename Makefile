# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 12:13:02 by gkamanur          #+#    #+#              #
#    Updated: 2025/04/02 14:31:16 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractl

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

RM = rm -rf
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

SRCS = src/main.c \
       src/utils.c \
       src/fractal_init.c \
       src/draw.c \
       src/calculation.c \
       src/string.c

OBJS = $(SRCS:.c=.o)
HDRS = src/fractl.h src/colors.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



