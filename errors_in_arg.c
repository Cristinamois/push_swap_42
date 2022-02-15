/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_in_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:50:22 by cmois             #+#    #+#             */
/*   Updated: 2021/12/31 10:46:52 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup_numbers(long long number, char **av, int i)
{
	i += 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == number)
			return (1);
		i++;
	}
	return (0);
}

int	is_not_number(char	*number)
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_it_int(long nbr)
{
	if (nbr > -2147483649 && nbr < 2147483648)
		return (1);
	return (0);
}

int	already_sorted(t_lst **a)
{
	t_lst	*tmp;

	tmp = (*a);
	while (tmp)
	{
		while (tmp->nbr < tmp->next->nbr)
		{
			tmp = tmp->next;
			if (tmp->next == NULL)
				return (1);
		}
		if (tmp->nbr > tmp->next->nbr)
			return (0);
	}
	return (1);
}

int	check_errors_from_args(char **av)
{
	int			i;
	long long	arg_nbr;
	char		**rep_av;

	rep_av = av;
	i = 1;
	while (rep_av[i])
	{
		arg_nbr = ft_atoi(rep_av[i]);
		if (arg_nbr > 2147483647 || arg_nbr < -2147483648)
			return (0);
		if (!(is_it_int(ft_atoi(av[i]))) || !(is_not_number(rep_av[i]))
			|| check_dup_numbers(arg_nbr, rep_av, i)
			|| !(ft_len_int(rep_av[i])))
			return (0);
		i++;
	}
	return (1);
}
