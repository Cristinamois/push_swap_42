/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_care_part_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:52:20 by cmois             #+#    #+#             */
/*   Updated: 2021/12/20 11:57:12 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	afficher_stack(t_lst **lst)
{
	t_lst	*rep;

	rep = (*lst);
	printf("\n");
	while (rep)
	{
		printf("[%ld]\t[%d]\n", rep->nbr, rep->index_pos);
		rep = rep->next;
	}
}
