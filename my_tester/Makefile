# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 20:48:07 by bammar            #+#    #+#              #
#    Updated: 2023/06/23 01:08:46 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_DICT =	../ft

NAME	=	tester

FLAG	=	ft

VECFILES=	tests/vector/constructor.cpp \
			tests/vector/vector.cpp

CXX		=	c++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98 -g

VECOBJS	=	$(VECFILES:.cpp=.o)

.cpp.o:
	$(CXX) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -c $< -o $(<:.cpp=.o)


all: 		fclean test 

ft_vector: FLAG = ft
ft_vector: $(VECOBJS)
	$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)

std_vector: FLAG = std
std_vector: clean $(VECOBJS)
	$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)

$(NAME): ft_vector
	$(MAKE) std_vector

vector:	clean ft_vector
	$(MAKE) clean
	$(MAKE) std_vector
	mkdir -p out
	./ft > out/ft_out
	./std > out/std_out
	$(MAKE) fclean

test:	vector

clean:
			rm -f $(VECOBJS)

fclean:		clean
			rm -f ft std

re:			fclean all

.PHONY:		all clean fclean re $(NAME) vector