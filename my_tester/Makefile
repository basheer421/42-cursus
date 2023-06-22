# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 20:48:07 by bammar            #+#    #+#              #
#    Updated: 2023/06/22 23:08:39 by bammar           ###   ########.fr        #
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

OBJDIR_FT = ft_objs
OBJDIR_STD = std_objs

.cpp.o:
			mkdir -p $(OBJDIR_FT)
			$(CXX) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -c $< -o $(OBJDIR_FT)/${<:.cpp=.o}

all: 		$(NAME)

ft_vector: FLAG = ft
ft_vector: $(VECOBJS)
	$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)
	@find $(VECOBJS) -type f -exec mv {} $(OBJDIR_FT) \;

std_vector: FLAG = std
std_vector: $(VECOBJS)
	$(CXX) $(VECOBJS) $(CXXFLAGS) -I $(FT_DICT) -D NAMESPACE=$(FLAG) -o $(FLAG)
	@find . -name "*.o" -exec mv {} $(OBJDIR_STD) \;

$(NAME): ft_vector
	$(eval FLAG = std)
	$(MAKE) std_vector

test:	ft_vector std_vector
		mkdir -p out
		./ft > out/ft_out
		./std > out/std_out

clean:
			rm -f $(VECOBJS)

fclean:		clean
			rm -f ft std
			rm -rf out

re:			fclean all

.PHONY:		all clean fclean re $(NAME)