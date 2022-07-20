#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*tempbuf;
	int i;

	buf = malloc(BUFFER_SIZE);
	tempbuf = malloc(1);
	if (buf == NULL || tempbuf == NULL)
		return (0);
    i = 0;
	while (read(fd, tempbuf, 1) > 0 && tempbuf[0] != '\n')
	{
		
		if (i >= BUFFER_SIZE)
			return (NULL);
		buf[i++] = tempbuf[0];
	}
	if (tempbuf[0] == 0)
		return (NULL);
	buf[i] = 0;
	free(tempbuf);
	return (buf);
}
/* TEST
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int file;

	file = open("test.txt",
	O_RDONLY, S_IRWXU | S_IRWXO | S_IRWXG);
	char *s = get_next_line(file);
	printf("output: %s\n", s);
	s = get_next_line(file);
	printf("output: %s\n", s);
	s = get_next_line(file);
	printf("output: %s\n", s);
	s = get_next_line(file);
	printf("output: %s\n", s);
	s = get_next_line(file);
	printf("output: %s\n", s);
	free(s);
	close(file);
    return (0);
}
*/