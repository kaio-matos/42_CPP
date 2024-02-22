
NAME=intern
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore
	echo "*_shrubbery" >> .gitignore

run: re
	./$(NAME)

valgrind: re
	valgrind ./$(NAME)

preprocess:
	c++ -E $(FILES) > preprocessed.hpp

fclean: clean
	rm -f $(NAME)

clean:
	rm -f .gitignore

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run preprocess
