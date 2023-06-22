# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 20:48:07 by bammar            #+#    #+#              #
#    Updated: 2023/06/23 01:32:41 by bammar           ###   ########.fr        #
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
	@$(CXX) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -c $< -o $(<:.cpp=.o)


all: 		fclean test 

ft_vector: FLAG = ft
ft_vector: $(VECOBJS)
	@$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)

std_vector: FLAG = std
std_vector: clean $(VECOBJS)
	@$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)

$(NAME): ft_vector
	@$(MAKE) --no-print-directory std_vector

vector:	clean ft_vector
	@rm -rf out
	@$(MAKE) --no-print-directory clean
	@$(MAKE) --no-print-directory std_vector
	@mkdir -p out
	@./ft > out/ft_vector
	@./std > out/std_vector
	@valgrind --leak-check=full ./ft 2> out/ft_vector_leaks > /dev/null
	@valgrind --leak-check=full ./std 2> out/std_vector_leaks > /dev/null
	@$(MAKE) --no-print-directory fclean

test:	vector

clean:
			@rm -f $(VECOBJS)

fclean:		clean
			@rm -f ft std

re:			fclean all

.PHONY:		all clean fclean re $(NAME) vector