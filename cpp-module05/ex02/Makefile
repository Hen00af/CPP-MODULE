# **************************************************************************** #
# MAKEFILE for ex01 - build using ../ex00/bureaucrat.cpp
# Targets: all, clean, fclean, re
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I../ex01
DEPFLAGS = -MMD -MP
NAME = form-up!
SRCS = main.cpp ./bureaucrat.cpp ./form.cpp ./ShrubberyCreationForm.cpp ./RobotomyRequestForm.cpp ./PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
