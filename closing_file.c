/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:54:28 by cmois             #+#    #+#             */
/*   Updated: 2021/12/27 09:05:58 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_shit(t_sorting *sorting, t_numbers *numbers)
{
	if (numbers)
		free(numbers);
	if (sorting)
		free(sorting);
	numbers = NULL;
	sorting = NULL;
}

void	free_all(t_sorting *sorting, t_numbers *numbers, t_lst **a, t_lst **b)
{
	if (a)
		ft_lstclearsarace(a);
	if (b)
		ft_lstclearsarace(b);
	free_shit(sorting, numbers);
	exit(0);
}

void	close_properly(char *str, t_numbers *numbers, t_sorting *sorting)
{
	ft_putendl_fd(str, 2);
	free_shit(sorting, numbers);
}

void	close_2_norm(t_lst *a, t_lst *b)
{
	free_all(NULL, NULL, &a, &b);
	exit (0);
}
