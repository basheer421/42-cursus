/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:13:18 by bammar            #+#    #+#             */
/*   Updated: 2022/12/22 15:24:02 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_ps *ps, int size)
{
	push2b(ps, size);
	if (!is_sorted(ps->a))
		sort3(ps, size);
	repush2b(ps, size);
}
