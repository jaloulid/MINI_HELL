SOURCE = 

OBJECT = $(SOURCE:.c=.o)

CC = cc


CFLAGS = -Wall -Werror -Wextra 
NAME = minishell.a

all : $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT) 

clean :
	rm -f  $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all
