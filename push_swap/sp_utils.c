/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:53:03 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 18:18:14 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sp_numcount(char **nums)
{
	int		count;

	if (!nums)
		return (0);
	count = 0;
	while (nums[count] != NULL)
		count++;
	return (count);
}

void	sp_free(char **arrays)
{
	int	i;

	if (!arrays)
		return ;
	i = 0;
	while (arrays[i] != NULL)
		free(arrays[i++]);
	free(arrays);
}
