NAME = minishell

sources = main.c \
			struct.c

object = $(sources:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(object)
	$(CC) $(CFLAGS) $(object) -lreadline -lncurses -o $(NAME)

clean:
	rm -rf $(object)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.SECONDARY: $(object)
.PHONY: clean