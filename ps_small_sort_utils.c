/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:19:45 by bammar            #+#    #+#             */
/*   Updated: 2022/12/22 15:21:39 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_ps *ps)
{
	swap_top(ps->a);
	ft_putstr_fd("sa\n", 1);
}

static void	rotate_a(t_ps *ps)
{
	rotate(ps->a);
	ft_putstr_fd("ra\n", 1);
}

void	push2b(t_ps *ps, int size)
{
	if (size < 4)
		return ;
	while (ps->a->head->content != 0)
		rotate_a(ps);
	push_from(ps->a, ps->b);
	ft_putstr_fd("pb\n", 1);
	ft_dqdel_first(ps->s);
	if (size == 5)
	{
		while (ps->a->head->content != 1)
			rotate_a(ps);
		push_from(ps->a, ps->b);
		ft_putstr_fd("pb\n", 1);
		ft_dqdel_first(ps->s);
	}
}

void	repush2b(t_ps *ps, int size)
{
	if (size < 4)
		return ;
	push_from(ps->b, ps->a);
	ft_putstr_fd("pa\n", 1);
	if (size == 5)
	{
		push_from(ps->b, ps->a);
		ft_putstr_fd("pa\n", 1);
	}
}

void	sort3(t_ps *ps, int size)
{
	if (ps->a->head->content == ps->s->head->content || size == 2)
	{
		swap_a(ps);
		rotate_a(ps);
	}
	else if (ps->a->head->content == ps->s->tail->content)
	{
		rotate_a(ps);
		if (ps->a->head->content > ps->a->head->next->content)
			swap_a(ps);
	}
	else
	{
		if (ps->a->tail->content == ps->s->head->content)
		{
			rrotate(ps->a);
			ft_putstr_fd("rra\n", 1);
		}
		else
			swap_a(ps);
	}
}
