#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	i;
	size_t	file_size;
	char	*buf;
	//static char	*line_start;

	file_size = get_file_size(fd);
	if (file_size == 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	// if buffer size is less than the line length NULL will be returned
    while (i < BUFFER_SIZE)
	{
		read(fd, buf, 1);
		printf("%s", buf);
		i++;
	}
	printf("\n");
	return (buf);
}


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int file;

	file = open("test.txt",
	O_RDONLY, S_IRWXU | S_IRWXO | S_IRWXG);
	char *s = get_next_line(file);
	// printf("output: %s\n", s);
	free(s);
	close(file);
    return (0);
}