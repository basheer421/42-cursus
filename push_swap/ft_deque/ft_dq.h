/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:12:06 by bammar            #+#    #+#             */
/*   Updated: 2022/12/19 18:25:22 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DQ_H
# define FT_DQ_H

# include "../libft/libft.h"

typedef struct s_dlist
{
	int					content;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}				t_dlist;

t_dlist	*ftdlst_new(int content);

typedef struct s_dq
{
	t_dlist	*head;
	t_dlist	*tail;
}					t_dq;

t_dq	*ftdq_new(void);
void	ft_dqadd_first(t_dq *lst, t_dlist *new);
void	ft_dqadd_last(t_dq *lst, t_dlist *new);
void	ft_dqdel_first(t_dq *lst);
void	ft_dqdel_last(t_dq *lst);
size_t	ft_dqsize(t_dq *lst);
int		ft_dqcontains(t_dq *dq, int item);

#endif