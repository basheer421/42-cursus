/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dqnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:28:46 by bammar            #+#    #+#             */
/*   Updated: 2022/11/12 22:40:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dq.h"

t_dq	*ftdq_new(void)
{
	t_dq	*dq;

	dq = malloc(sizeof(t_dq));
	if (!dq)
		return (NULL);
	dq -> head = NULL;
	dq -> tail = NULL;
	return (dq);
}
