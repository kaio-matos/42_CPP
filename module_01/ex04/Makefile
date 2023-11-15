
NAME=sed_is_for_loosers
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME) sherlock Adventure AVENTURA

valgrind: re
	valgrind ./$(NAME) sherlock Adventure AVENTURA

fclean:
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run
