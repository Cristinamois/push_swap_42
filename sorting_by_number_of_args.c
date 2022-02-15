/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_by_number_of_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:25:26 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 15:44:50 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args(t_lst **a)
{
	int		first;
	int		second;
	int		third;
	t_lst	*tmp;

	tmp = (*a);
	first = tmp->nbr;
	second = tmp->next->nbr;
	third = tmp->next->next->nbr;
	if (first > second && second > third && third < first)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if (first > second && second < third && third > first)
		swap_a(a);
	else if (first > second && second < third && third < first)
		rotate_a(a);
	else if (first < second && second > third && third < first)
		reverse_rotate_a(a);
	else if (first < second && second > third && third > first)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
}
