/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:36:52 by bammar            #+#    #+#             */
/*   Updated: 2022/09/13 23:02:10 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int	main(void)
{
	int		file;
	char	*s;

	file = open("test.txt",
			O_RDONLY,
			S_IRWXU | S_IRWXO | S_IRWXG);
	while ((s = get_next_line(file)))
		printf("%s", s);
	// s = get_next_line(file);
	// printf("%s", s);
	free(s);
	close(file);
	return (0);
}
