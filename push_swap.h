/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:44:49 by cmois             #+#    #+#             */
/*   Updated: 2021/12/31 10:51:01 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_lst
{
	long				nbr;
	int					index_pos;
	struct s_lst		*next;
}				t_lst;

typedef struct s_numbers
{
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	last;
}				t_numbers;

typedef struct s_sorting
{
	int	index;
	int	proximity;
	int	lowest_number;
	int	changing_index;
}				t_sorting;

/*Afficher stack pour voir resultat visuellement*/
void	afficher_stack(t_lst **lst);
/*----------------------------------------------*/
void	close_properly(char *str, t_numbers *numbers, t_sorting *sorting);
void	close_2_norm(t_lst *a, t_lst *b);
int		check_errors_from_args(char **av);
t_lst	*lst_new(int nbr);
int		lst_size(t_lst **a);
int		is_it_int(long nbr);
int		ft_len_int(char *str);
void	lstadd_first(t_lst **list, int nbr);
void	lstadd_end(t_lst **first, int nbr);
void	give_value_of_index_pos(t_lst **a);
void	give_value_to_nbr_struct(t_lst **a, t_numbers *numbers);
void	three_args(t_lst **a);
void	five_args(t_lst **a, t_lst **b, t_sorting *sorting);
void	swap_a(t_lst **a);
void	swap_b(t_lst **b);
void	swap_both(t_lst **a, t_lst **b);
void	push_b(t_lst **a, t_lst **b);
void	push_a(t_lst **a, t_lst **b);
void	rotate_a(t_lst **a);
void	rotate_b(t_lst **b);
void	rotate_both(t_lst **a, t_lst **b);
void	reverse_rotate_a(t_lst **a);
void	reverse_rotate_b(t_lst **b);
void	reverse_rotate_both(t_lst **a, t_lst **b);
void	radix_sort(t_lst **a, t_lst **b);
void	incognito_sorting(t_lst **a, t_lst **b, t_sorting *sorting);
void	give_value_to_sorting_values(t_sorting *sorting, t_lst **a);
void	case_its_lowest(t_sorting *sorting, t_lst **a, t_lst **b, t_lst *rep_a);
void	do_the_job(t_lst **a, t_lst **b, t_sorting *sorting, t_lst *rep_a);
void	ft_lstclearsarace(t_lst **lst);
void	free_all(t_sorting *sorting, t_numbers *numbers, t_lst **a, t_lst **b);
int		already_sorted(t_lst **a);
int		check_int(t_lst **a);
#endif
