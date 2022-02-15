/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:55:25 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 15:43:01 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_lst **a)
{
	t_lst	*address_prev;
	t_lst	*futur_second;

	futur_second = *a;
	while ((*a)->next)
	{
		address_prev = *a;
		*a = (*a)->next;
	}
	(*a)->next = futur_second;
	address_prev->next = NULL;
}

void	reverse_rotate_a(t_lst **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_lst **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_botch(t_lst **a, t_lst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
