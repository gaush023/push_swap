/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/21 18:01:42 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"
#include <stdio.h>

static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		ft_pb(stack_a, stack_b);
	printf("situation_one\n");
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

static void	do_the_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*bottom_a;
	t_list	*bottom_b;
	int		bottom_a_value;
	int		bottom_b_value;

	bottom_a = *stack_a;
	bottom_b = *stack_b;
	bottom_a_value = (mv_last(bottom_a))->value;
	bottom_b_value = (mv_last(bottom_b))->value;
	if ((*stack_a)->value > (*stack_b)->value || !*stack_b)
		situation_one(stack_a, stack_b);
	else if ((*stack_a)->value < bottom_b_value)
		situation_two(stack_a, stack_b, bottom_a_value);
	else
		situation_three(stack_a, stack_b, bottom_a_value, bottom_b_value);
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	int	n;

	printf("bbbbbbbbbbbbbbbbbbb");
	while (ft_lstsize(*stack_a) != 3)
	{
		printf("aaaaaaaaaaaaa");
		n = is_sorted_stack_a(stack_a);
		if (n <= 1)
			break;
			// return (done_the_sort_type_a(stack_a, stack_b));
		do_the_sort(stack_a, stack_b);
	}
	magic_sort_3(stack_a);
}
