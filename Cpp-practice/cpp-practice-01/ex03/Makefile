# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 01:18:44 by bammar            #+#    #+#              #
#    Updated: 2023/02/17 22:36:29 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

FILES	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98
OBJS	=	$(FILES:.cpp=.o)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			${RM} -f $(OBJS)

fclean:		clean
			${RM} -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
