/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:41:04 by cmois             #+#    #+#             */
/*   Updated: 2021/12/14 13:51:18 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **lst)
{
	t_lst	*first;
	t_lst	*second;
	t_lst	*third;

	first = *lst;
	second = (*lst)->next;
	*lst = (*lst)->next;
	third = (*lst)->next;
	*lst = first;
	first->next = third;
	second->next = first;
	*lst = second;
}

void	swap_a(t_lst **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_lst **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_lst **a, t_lst **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
