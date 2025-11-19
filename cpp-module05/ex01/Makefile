# **************************************************************************** #
# MAKEFILE for ex01 - build using ../ex00/bureaucrat.cpp
# Targets: all, clean, fclean, re
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I../ex01
NAME = bureaucrat
SRCS = main.cpp ./bureaucrat.cpp ./form.cpp
OBJS = main.o bureaucrat.o
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bureaucrat.o: ./bureaucrat.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

form.o: ./form.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
