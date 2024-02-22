
NAME=bureaucrat
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp Bureaucrat.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME)

valgrind: re
	valgrind ./$(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f .gitignore

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run
