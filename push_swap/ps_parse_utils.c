/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:58 by bammar            #+#    #+#             */
/*   Updated: 2022/12/23 17:49:32 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_dqfill(t_dq *dq, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_dqadd_last(dq, ftdlst_new(tab[i]));
		if (dq->tail == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void	ps_dqfree(t_dq *dq)
{
	if (!dq)
		return ;
	while (dq->head != NULL)
		ft_dqdel_first(dq);
}

int	is_valid_num(long num, char *string)
{
	char	*itoa_string;

	if (!string)
		return (0);
	itoa_string = ft_itoa(num);
	if (!itoa_string)
		return (0);
	while (is_space(*string))
		string++;
	if ((!string) || (*string == '\0') || (ft_strncmp(itoa_string, string
				+ (string[0] == '+'), ft_strlen(string)
				+ (string[0] == '+')) != 0) || ((num == 0)
			&& (ft_strncmp(string, "0", 1) != 0)) || ((num == -1)
			&& (ft_strncmp(string, "-1", 2) != 0)) || (num < INT_MIN)
		|| (num > INT_MAX))
		return (free(itoa_string), 0);
	free(itoa_string);
	return (1);
}
