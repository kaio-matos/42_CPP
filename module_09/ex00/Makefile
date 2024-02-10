
NAME=btc
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp BitcoinExchange.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME) input.txt

valgrind: re
	valgrind ./$(NAME) input.txt

fclean:
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run test
