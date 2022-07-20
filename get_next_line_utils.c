#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	get_file_size(int fd)
{
	size_t	size;
	unsigned char	*bytes;
	
	bytes = malloc(1);
	if (read(fd, bytes, 1) < 0)
		return (0);
	size = 0;
	while (read(fd, bytes, 1) != 0)
		size++;
	size++;
	free(bytes);
	return (size);
}