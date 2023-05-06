# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 01:18:44 by bammar            #+#    #+#              #
#    Updated: 2023/04/05 04:18:48 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

FILES	=	main.cpp Fixed.cpp

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	=	$(FILES:.cpp=.o)

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			${RM} -f $(OBJS)

fclean:		clean
			${RM} -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
