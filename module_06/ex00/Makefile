
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
	@echo
	./$(NAME) nan
	@echo
	./$(NAME) 42.0f
	@echo
	./$(NAME) 0003.4f
	@echo
	./$(NAME) "2222392 a"
	@echo
	./$(NAME) 256
	@echo
	./$(NAME) -1
	@echo
	./$(NAME) 123456.3232
	@echo
	./$(NAME) -123456.3232
	@echo
	./$(NAME) +inf
	@echo
	./$(NAME) -inf

valgrind: re
	valgrind ./$(NAME)

clean:
	rm -f .gitignore

fclean: clean
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run test
