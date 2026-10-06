# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 01:18:44 by bammar            #+#    #+#              #
#    Updated: 2023/02/17 23:25:56 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

FILES	=	main.cpp

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
