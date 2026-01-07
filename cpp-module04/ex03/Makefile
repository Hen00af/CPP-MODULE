CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME   = interface_recap
OBJDIR = obj

SRCS = cpp/Aclass.cpp \
       cpp/lMateriaSource.cpp \
       cpp/lcharacter.cpp \
       cpp/main.cpp

OBJS = $(SRCS:cpp/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: cpp/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
