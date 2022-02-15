/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:30:44 by cmois             #+#    #+#             */
/*   Updated: 2021/12/21 16:52:32 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_value_to_nbr_struct(t_lst **a, t_numbers *numbers)
{
	t_lst	*rep;

	rep = (*a);
	numbers->first = rep->nbr;
	numbers->second = rep->next->nbr;
	numbers->third = rep->next->next->nbr;
	numbers->fourth = rep->next->next->next->nbr;
	if (rep->next->next->next->next == NULL)
		numbers->last = 0;
	else
		numbers->last = rep->next->next->next->next->nbr;
}

int	best_shit(t_lst **a, int index)
{
	t_lst	*lst;
	int		rotate;
	int		len;

	rotate = 0;
	lst = (*a);
	len = lst_size(a) / 2;
	while (lst->index_pos != index)
	{
		lst = lst->next;
		rotate++;
	}
	if (rotate > len)
		return (rotate);
	else
		return (0);
}

void	do_the_fingjob(int repere, t_lst *rep_a, t_sorting *sorting, t_lst **a)
{
	if (repere == 1)
	{
		while ((*a)->nbr != sorting->lowest_number)
		{
			rotate_a(a);
			rep_a = (*a);
		}
	}
	if (repere == 2)
	{
		while ((*a)->nbr != sorting->lowest_number)
		{
			reverse_rotate_a(a);
			rep_a = (*a);
		}
	}
	(void)rep_a;
}

void	five_args(t_lst **a, t_lst **b, t_sorting *sorting)
{
	t_lst	*rep_a;
	int		i;

	i = 0;
	rep_a = (*a);
	give_value_to_sorting_values(sorting, a);
	while (i != 2)
	{
		if (!best_shit(a, i))
			do_the_fingjob(1, rep_a, sorting, a);
		else
			do_the_fingjob(2, rep_a, sorting, a);
		case_its_lowest(sorting, a, b, rep_a);
		i++;
	}
	if (lst_size(a) == 3)
		three_args(a);
	while ((*b))
		push_a(a, b);
}
