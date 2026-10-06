/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:36:52 by bammar            #+#    #+#             */
/*   Updated: 2022/09/16 18:24:41 by bammar           ###   ########.fr       */
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
	size_t 	i;
	file = open("en.daryabadi.txt",
			O_RDONLY);
	i = 0;
	while ((s = get_next_line(file)))
	{
		printf("%s\n", s);
		free(s);
		i++;
	}
	free(s);
	printf("line count: %lu\n", i);
	close(file);
	return (0);
}
