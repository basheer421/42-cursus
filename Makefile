UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
    VALGRIND = valgrind -q --leak-check=full
endif

FILES = get_next_line.c get_next_line_utils.c main.c
CFLAGS = -Wall -Wextra -Werror
OUT = gnlTest

all:
	@cc $(CFLAGS) $(FILES) -o $(OUT) && $(VALGRIND) ./$(OUT)

dockerb:
	@docker build -qt val . > /dev/null
	@docker run -dti --privileged --name basheer42 -v $(shell pwd):/project/ val > /dev/null

dockere:
	@docker exec basheer42 make

dockerc_dng:
	@docker rmi $(shell docker images -f "dangling=true" -q) > /dev/null 2>&1 || true

dockerc: dockerc_dng
	@docker rm -f basheer42 > /dev/null

valgrind: dockerb dockere dockerc

.PHONY: all dockerb dockere dockerc valgrind
