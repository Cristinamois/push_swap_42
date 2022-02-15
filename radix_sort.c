/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:34:44 by cmois             #+#    #+#             */
/*   Updated: 2021/12/14 13:46:55 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_lst **lst)
{
	t_lst	*first;
	int		max;
	int		max_bits;

	first = (*lst);
	max = first->index_pos;
	max_bits = 0;
	while (first)
	{
		if (first->index_pos > max)
			max = first->index_pos;
		first = first->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_lst **a, t_lst **b)
{
	t_lst	*rep_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	rep_a = (*a);
	size = lst_size(&rep_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			rep_a = *a;
			if (((rep_a->index_pos >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
		}
		while ((*b))
			push_a(a, b);
		i++;
	}
}
