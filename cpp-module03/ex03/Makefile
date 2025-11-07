NAME		:= DiamondTrap

CXXFLAGS	:= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98

SRCS		:= main.cpp
SRCS		+= ClapTrap.cpp

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: all clean
all: $(NAME)

fclean: clean all

clean:
	$(RM) $(NAME)

re: fclean all