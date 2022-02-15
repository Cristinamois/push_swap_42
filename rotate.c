/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:50:55 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 15:11:52 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **lst)
{
	t_lst	*second;
	t_lst	*before;

	before = (*lst);
	second = (*lst)->next;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = before;
	before->next = NULL;
	*lst = second;
}

void	rotate_a(t_lst **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_lst **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rotate_both(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
