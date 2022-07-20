NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= $(shell bash -c 'read -p "BUFFER_SIZE: " BUFFER_SIZE; echo $$BUFFER_SIZE')

all: $(NAME)

$(NAME): # 		Compile
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $@*.c $@.h -o $@

clean: #		Removes all .o files
	rm -f *.o

fclean:	clean # Removes the exe file
	rm $(NAME)

re: #			Removes .a file and redo
	fclean all

run: $(NAME)
	./$(NAME)

rerun:	fclean all
	./$(NAME)