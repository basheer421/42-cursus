/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:35 by bammar            #+#    #+#             */
/*   Updated: 2022/12/20 15:40:49 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_dq *a)
{
	t_dlist	*node1;

	node1 = a->head;
	if (!node1)
		return (0);
	while (node1->next)
	{
		if (node1->content > node1->next->content)
			return (0);
		node1 = node1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc == 1)
		return (0);
	ps = ps_init(argc, argv);
	if (!ps)
		return (ft_putstr_fd("Error\nInvalid Arguments\n", 2), 1);
	if (!is_sorted(ps->a))
	{
		if (ft_dqsize(ps->a) <= 5)
			small_sort(ps, ft_dqsize(ps->a));
		else
		{
			radix(ps);
			push_back(ps);
		}
	}
	if (argc == 2)
		sp_free(ps->argv);
	free(ps);
	return (0);
}
