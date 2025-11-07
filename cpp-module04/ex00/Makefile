CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic 
NAME = animal
SRCS = main.cpp animal.cpp dog.cpp cat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
debug: CXXFLAGS += -g -fsanitize=address -fno-omit-frame-pointer
debug: re
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re