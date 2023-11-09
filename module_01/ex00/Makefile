
NAME=zombie
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

run: re
	./$(NAME)

valgrind: re
	valgrind ./$(NAME)

fclean:
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re valgrind run
