NAME = minishell
SRC = main_parseng.c lexer.c lexer_word.c lexer_utils.c lexer_free.c parser_utils.c parser_free.c \
		parser_args.c parcer.c parce_redir.c parser_utils2.c \
		env_utils.c env_helper.c \
		expand_dollar.c expand_var.c expand_utils.c expand_cmd.c global.c
 #parser_print.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I.

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re