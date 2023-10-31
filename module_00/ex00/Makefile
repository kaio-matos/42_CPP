
NAME=megaphone
FLAGS= -Wall -Wextra -Werror -std=c++98

FILES=megaphone.cpp

all: $(NAME);

$(NAME):
	c++ $(FLAGS) $(FILES) -o $(NAME)
	echo $(NAME) > .gitignore

fclean:
	rm -f $(NAME)

re: fclean all;


################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean fclean re rebuild debug
