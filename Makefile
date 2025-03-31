NAME = fractl

CC = cc -g
#CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

# MiniLibX library settings
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Source and Object files
SRCS = main.c utils.c errors.c fractal_init.c draw.c calculation.c 
OBJS = $(SRCS:.c=.o)

# Header files
HDRS = fractl.h colors.h

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compiling object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

# Cleanup rules
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Phony targets (avoid conflicts with files of the same name)
.PHONY: all clean fclean re

