/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:09:26 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 18:15:09 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_top(t_dq *dq)
{
	t_dlist	*first_top;
	t_dlist	*new_top;

	if (!dq)
		return (-1);
	first_top = ftdlst_new(dq->head->content);
	if (!first_top)
		return (-1);
	ft_dqdel_first(dq);
	new_top = ftdlst_new(dq->head->content);
	if (!new_top)
		return (-1);
	ft_dqdel_first(dq);
	ft_dqadd_first(dq, first_top);
	ft_dqadd_first(dq, new_top);
	return (0);
}

int	push_from(t_dq *src, t_dq *dst)
{
	t_dlist	*first_top;

	if (!src || !dst || src->head == NULL)
		return (-1);
	first_top = ftdlst_new(src->head->content);
	if (!first_top)
		return (-1);
	ft_dqdel_first(src);
	ft_dqadd_first(dst, first_top);
	return (0);
}

int	rotate(t_dq *dq)
{
	t_dlist	*first_top;

	if (!dq)
		return (-1);
	first_top = ftdlst_new(dq->head->content);
	if (!first_top)
		return (-1);
	ft_dqdel_first(dq);
	ft_dqadd_last(dq, first_top);
	return (0);
}

int	rrotate(t_dq *dq)
{
	t_dlist	*first_bottom;

	if (!dq)
		return (-1);
	first_bottom = ftdlst_new(dq->tail->content);
	if (!first_bottom)
		return (-1);
	ft_dqdel_last(dq);
	ft_dqadd_first(dq, first_bottom);
	return (0);
}
