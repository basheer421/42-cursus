/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:44:09 by bammar            #+#    #+#             */
/*   Updated: 2022/09/15 19:10:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*s2;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		s[i] = s2[i - s1_len];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*empty_string(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;
	size_t	strlen;
	size_t	char_count;

	if (!s || (size_t)start >= ft_strlen((char *)s)
		|| ft_strlen((char *)s) == 0)
		return (empty_string());
	strlen = ft_strlen((char *)s);
	char_count = 0;
	if (len + start < strlen)
		char_count = (len);
	else
		char_count = (strlen - (size_t)start);
	s2 = malloc(char_count + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < char_count)
	{
		s2[i] = s[i + (size_t)start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
