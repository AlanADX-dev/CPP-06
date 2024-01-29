SRCS = Base.cpp main.cpp

NAME = ex02

CFLAG = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
