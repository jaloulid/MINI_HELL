NAME = minishell

SRC = main_parseng.c parsing/lexer.c parsing/lexer_word.c parsing/lexer_utils.c parsing/lexer_free.c parsing/parser_utils.c parsing/parser_free.c \
parsing/parser_args.c parsing/parcer.c parsing/parce_redir.c parsing/parser_utils2.c parsing/env_helper.c \
parsing/expand_dollar.c parsing/expand_var.c parsing/expand_utils.c parsing/expand_cmd.c parsing/global.c \
builtins/built_ins.c builtins/built_utils.c builtins/env_utils.c builtins/sort_env.c \
builtins/exit.c excution/exec_cmd.c excution/find_paths.c pipes/pipe_handle.c \
file_management/handle_files.c


OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS =  #fsanitize=address -g3 

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