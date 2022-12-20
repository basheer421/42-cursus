/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:17:08 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 19:50:20 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int num, t_dlist *lst)
{
	t_dlist	*node;
	int		index;

	index = 0;
	node = lst;
	while (node)
	{
		if (node->content == num)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}

void	ps_destroy(t_ps *ps)
{
	ps_dqfree(ps->a);
	ps_dqfree(ps->b);
	ps_dqfree(ps->s);
	free(ps->a);
	free(ps->b);
	free(ps->s);
	free(ps);
}
