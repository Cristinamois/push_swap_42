/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:47:04 by cmois             #+#    #+#             */
/*   Updated: 2021/12/19 12:16:28 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_lst **home, t_lst **destination)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = *destination;
	tmp2 = (*home)->next;
	*destination = *home;
	(*destination)->next = tmp;
	*home = tmp2;
}

void	push_a(t_lst **a, t_lst **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_lst **a, t_lst **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
