# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 23:22:01 by bammar            #+#    #+#              #
#    Updated: 2023/06/26 01:25:05 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	PmergeMe

FILES	=	main.cpp PmergeMe.cpp

CXX		=	c++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

OBJS	=	$(FILES:.cpp=.o)

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
