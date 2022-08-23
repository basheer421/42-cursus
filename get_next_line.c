/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:36:07 by bammar            #+#    #+#             */
/*   Updated: 2022/08/14 19:01:54 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*tempbuf;
	int		i;

	buf = malloc(BUFFER_SIZE + 1);
	tempbuf = malloc(1);
	if (!buf || !tempbuf)
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

// #include <fcntl.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int	main(void)
// {
// 	int		file;
// 	char	*s;

// 	file = open("test.txt",
// 				O_RDONLY,
// 				S_IRWXU | S_IRWXO | S_IRWXG);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	s = get_next_line(file);
// 	printf("%s\n", s);
// 	free(s);
// 	close(file);
// 	return (0);
// }
