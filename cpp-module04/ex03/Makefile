CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Ih

NAME   = interface_recap
OBJDIR = obj

SRCS = cpp/Aclass.cpp \
       cpp/Ice.cpp \
       cpp/Cure.cpp \
       cpp/Character.cpp \
       cpp/MateriaSource.cpp \
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
