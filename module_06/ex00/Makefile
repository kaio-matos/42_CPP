
NAME=convert
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp ScalarConverter.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME)

test: re
	./$(NAME) 0
	./$(NAME) nan
	./$(NAME) 42.0f
	./$(NAME) 0003.4f
	./$(NAME) "2222392 a"
	./$(NAME) 256
	./$(NAME) -1
	./$(NAME) 123456.3232
	./$(NAME) -123456.3232
	./$(NAME) +inf
	./$(NAME) -inf

valgrind: re
	valgrind ./$(NAME)

fclean:
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run test
