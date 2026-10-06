/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:15:41 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 18:16:57 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static long	super_bad_case(int sign)
{
	if (sign == 1)
		return (-1);
	else if (sign == -1)
		return (0);
	return (1);
}

static long	bad_case(char *x, int sign, int y, int zrs)
{
	int		i;
	char	*max;

	if (y - zrs > 19)
		return (super_bad_case(sign));
	max = "9223372036854775808";
	if (sign == 1)
		max = "9223372036854775807";
	i = 0;
	while (x[i] != 0)
	{
		if (x[i] > max[i])
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		else if (x[i] < max[i])
			return (1);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int			i;
	int			y;
	long long	val;
	long		sign;
	int			zrs;

	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	val = 0;
	y = 0;
	zrs = 0;
	while (str[i + y] != 0 && (str[i + y] >= '0' && str[i + y] <= '9'))
	{
		val = (val * 10) + (str[i + y++] - '0');
		zrs += (val == 0);
	}
	if (y - zrs >= 19 && bad_case((char *)str + i + zrs, sign, y, zrs) != 1)
		return (bad_case((char *)str + i + zrs, sign, y, zrs));
	return (val * sign);
}

void	tab_sort(int *t, int size)
{
	int	i;
	int	y;
	int	min_index;
	int	temp;

	i = 0;
	while (i < size)
	{
		min_index = i;
		y = i;
		while (y < size)
		{
			if (t[y] < t[min_index])
				min_index = y;
			y++;
		}
		temp = t[i];
		t[i] = t[min_index];
		t[min_index] = temp;
		i++;
	}
}
