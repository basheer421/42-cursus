/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_retrun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:22:10 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 18:15:30 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	change_path(t_dq *dq, int *item, int n)
{
	t_dlist	*node;
	int		i;

	i = 0;
	node = dq->head;
	while (node && i++ < n / 2)
	{
		if (node->content == *item)
			return (0);
		node = node->next;
	}
	return (1);
}

void	look_in_b(t_ps *ps, int path)
{
	if (path == 0)
	{
		rotate(ps->b);
		ft_putstr_fd("rb\n", 1);
	}
	else
	{
		rrotate(ps->b);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	save_in_bottom(t_ps *ps)
{
	if (ps->s->tail && (ps->s->tail->prev
			&& ps->a->head->content == ps->s->tail->prev->content)
		&& ft_dqsize(ps->a) > 1)
	{
		rotate(ps->a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (ps->s->tail && ps->s->tail->content == ps->a->tail->content)
	{
		rrotate(ps->a);
		ft_putstr_fd("rra\n", 1);
		ft_dqdel_last(ps->s);
	}
}

void	push_back(t_ps *ps)
{
	int	path;

	while (ps->b->head)
	{
		path = change_path(ps->b, &ps->s->tail->content, ft_dqsize(ps->b));
		if (ps->b->head->content == ps->s->tail->content || (ps->s->tail->prev
				&& ps->b->head->content == ps->s->tail->prev->content))
		{
			if (ps->b->head->content == ps->s->tail->content)
				ft_dqdel_last(ps->s);
			push_from(ps->b, ps->a);
			ft_putstr_fd("pa\n", 1);
			save_in_bottom(ps);
		}
		else if (ft_dqcontains(ps->b, ps->s->tail->content))
			look_in_b(ps, path);
	}
}
