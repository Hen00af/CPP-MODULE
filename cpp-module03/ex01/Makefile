NAME		:= ClapTrap

CXXFLAGS	:= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98

SRCS		:= main.cpp
SRCS		+= ClapTrap.cpp

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: all clean
all: $(NAME)

clean:
	$(RM) $(NAME)
