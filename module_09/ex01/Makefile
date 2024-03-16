
NAME=RPN
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp RPN.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

valgrind: re
	valgrind ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

clean:
	rm -f .gitignore

fclean: clean
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run test
