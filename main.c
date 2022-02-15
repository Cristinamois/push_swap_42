/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:41 by cmois             #+#    #+#             */
/*   Updated: 2021/12/31 10:50:43 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_in_order(t_lst **a)
{
	t_lst	*replace;

	replace = (*a);
	while (replace->next)
	{
		if (replace->nbr < replace->next->nbr)
			replace = replace->next;
		if (replace->next == NULL)
			return (0);
		if (replace->nbr > replace->next->nbr)
			return (1);
		else
			replace = replace->next;
	}
	return (0);
}

int	put_numbers_in_list(t_lst **a, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_it_int(ft_atoi(av[i])) && ft_len_int(av[i]))
		{
			lstadd_end(a, ft_atoi(av[i]));
			if (!is_it_int((*a)->nbr))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

void	check_how_many_for_sort(t_lst **a, t_lst **b, t_sorting *sorting)
{
	int		len;
	t_lst	*lst;

	lst = (*a);
	len = lst_size(a);
	if (len == 2 && lst->nbr > lst->next->nbr)
		swap_a(a);
	else if (len == 3)
		three_args(a);
	else if (len == 4)
		incognito_sorting(a, b, sorting);
	else if (len == 5)
		five_args(a, b, sorting);
	else if (len > 5)
		radix_sort(a, b);
	else
		return ;
}

void	ft_lstclearsarace(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		if (*lst)
			free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}

int	main(int ac, char **av)
{
	t_lst		*a;
	t_lst		*b;
	t_numbers	*numbers;
	t_sorting	*sorting;

	if (ac <= 2)
		return (0);
	numbers = (t_numbers *)malloc(sizeof(t_numbers));
	sorting = (t_sorting *)malloc(sizeof(t_sorting));
	if (!numbers || !sorting)
		return (0);
	a = NULL;
	b = NULL;
	if (!(check_errors_from_args(av)) || !(put_numbers_in_list(&a, av))
		|| !check_int(&a))
	{
		close_properly("Error", numbers, sorting);
		close_2_norm(a, b);
	}
	if (already_sorted(&a))
		free_all(sorting, numbers, &a, &b);
	give_value_of_index_pos(&a);
	check_how_many_for_sort(&a, &b, sorting);
	free_all(sorting, numbers, &a, &b);
	return (0);
}
