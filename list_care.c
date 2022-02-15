/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_care.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:09:01 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 15:03:08 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lst_new(int nbr)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index_pos = -1;
	new->next = NULL;
	return (new);
}

void	lstadd_end(t_lst **first, int nbr)
{
	t_lst	*new;

	new = NULL;
	if (!(*first))
	{
		*first = lst_new(nbr);
		new = *first;
	}
	else if (first)
	{
		new = *first;
		while ((*first)->next)
		{
			*first = (*first)->next;
		}
		(*first)->next = lst_new(nbr);
	}
	*first = new;
}

void	lstadd_first(t_lst **list, int nbr)
{
	t_lst	*new;

	new = lst_new(nbr);
	new->next = (*list);
	*list = new;
}

int	lst_size(t_lst **a)
{
	t_lst	*rep;
	t_lst	*front;
	int		ret;

	ret = 1;
	front = (*a);
	rep = (*a);
	while (rep->next)
	{
		rep = rep->next;
		ret++;
	}
	rep = front;
	return (ret);
}
