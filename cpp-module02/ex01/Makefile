NAME        := My_First_Class_in_Orthodox_Canonical_Form

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS        := main.cpp \
               Fixed.cpp
OBJS        := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re