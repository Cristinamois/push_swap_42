/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incognito_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:37:31 by cmois             #+#    #+#             */
/*   Updated: 2021/12/27 08:57:14 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_lst	**lst, int number)
{
	int		ret;
	t_lst	*tmp;

	tmp = (*lst);
	ret = 0;
	while (tmp)
	{
		if (tmp->nbr == number)
			ret = tmp->index_pos;
		tmp = tmp->next;
	}
	return (ret);
}

int	get_min_num(t_lst **lst, int changing_index)
{
	int		ret;
	t_lst	*tmp;

	tmp = (*lst);
	ret = 0;
	ret = tmp->nbr;
	while (tmp)
	{
		if (tmp->index_pos == changing_index)
			ret = tmp->nbr;
		tmp = tmp->next;
	}
	return (ret);
}

void	give_value_to_sorting_values(t_sorting *sorting, t_lst **a)
{
	sorting->changing_index = 0;
	sorting->lowest_number = get_min_num(a, sorting->changing_index);
	sorting->index = get_index(a, sorting->lowest_number);
	sorting->proximity = (lst_size(a) / 2);
	if (lst_size(a) == 5)
		sorting->proximity = 2;
}

void	case_its_lowest(t_sorting *sorting, t_lst **a, t_lst **b, t_lst *rep_a)
{
	push_b(a, b);
	rep_a = (*a);
	sorting->changing_index++;
	sorting->lowest_number = get_min_num(&rep_a, sorting->changing_index);
}

void	incognito_sorting(t_lst **a, t_lst **b, t_sorting *sorting)
{
	t_lst	*rep_a;

	rep_a = (*a);
	give_value_to_sorting_values(sorting, a);
	while (lst_size(a) > 3)
	{
		if (rep_a->nbr == sorting->lowest_number)
			case_its_lowest(sorting, a, b, rep_a);
		else if (sorting->proximity > sorting->index)
		{
			rotate_a(a);
			rep_a = (*a);
		}
		else
		{
			reverse_rotate_a(a);
			rep_a = (*a);
		}
	}
	if (lst_size(a) == 3)
		three_args(a);
	while ((*b))
		push_a(a, b);
}
