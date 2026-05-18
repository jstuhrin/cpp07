
NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJS = main.o

%.o: %.cpp whatever.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re