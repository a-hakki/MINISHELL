NAME = minishell

sources = main.c \
			struct.c

object = $(sources:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft

lib = $(LIBFT_DIR)/libft.a


all: $(lib) $(NAME)

$(lib):
	make -C $(LIBFT_DIR)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) $(lib) -lreadline -lncurses -o $(NAME)

clean:
	rm -rf $(object)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.SECONDARY: $(object)
.PHONY: clean