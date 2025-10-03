# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shattori <shattori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:59:52 by shattori          #+#    #+#              #
#    Updated: 2025/10/02 01:34:13 by shattori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := megaphone

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -pedantic -Ilib
SRCS        := ./megaphone.cpp
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
