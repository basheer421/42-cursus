/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqcontains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:52 by bammar            #+#    #+#             */
/*   Updated: 2022/12/18 15:20:14 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dq.h"

int	ft_dqcontains(t_dq *dq, int item)
{
	t_dlist	*node;

	node = dq->head;
	while (node)
	{
		if (node->content == item)
			return (1);
		node = node->next;
	}
	return (0);
}
