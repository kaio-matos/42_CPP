
NAME=PmergeMe
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp PmergeMe.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME) 9 8 7 6 5 4 3 2 1 0

valgrind: re
	valgrind ./$(NAME) `shuf -i 1-100000 -n 100 | tr "\n" " "`

debug:
	@c++ $(FILES) -o $(NAME)

clean:
	rm -f .gitignore

fclean: clean
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run test
