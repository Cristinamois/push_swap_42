/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:59:00 by cmois             #+#    #+#             */
/*   Updated: 2021/12/31 10:51:25 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_len_int(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[j] == '-' || str[j] == '+')
	{
		++j;
		++i;
	}	
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[j] == '0')
		++j;
	while (ft_isdigit(str[i + j]))
		i++;
	return (i < 12);
}

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	return (result * sign);
}
