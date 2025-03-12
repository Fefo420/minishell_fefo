NAME = minishell

HEADER = minishell.h

LIBFT_DIR = ./libft_fefo
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c
OBJS = $(SRCS:.c=.o)

# CFLAGS: These are the flags used during the compilation of source files to object files.
# LINKFLAGS: These are the flags used during the linking stage to create the final executable.
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LINKFLAGS = -lreadline

all: $(LIBFT) $(NAME)

$(LIBFT):
	@git submodule update --init $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES) $(LINKFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re