/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_value_of_index_to_lst.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:16:44 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 12:43:36 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lowest_number(t_lst **a)
{
	t_lst	*head;
	t_lst	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *a;
	if (head)
	{
		while (head)
		{
			if ((head->index_pos == -1) && (!has_min || head->nbr < min->nbr))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	give_value_of_index_pos(t_lst **a)
{
	t_lst	*rep;
	int		index_pos;

	index_pos = 0;
	rep = lowest_number(a);
	while (rep)
	{
		rep->index_pos = index_pos++;
		rep = lowest_number(a);
	}
}
