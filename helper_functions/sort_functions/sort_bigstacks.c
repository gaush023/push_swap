/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/15 01:59:08 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"


static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		ft_pb(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value > (*stack_b)->value)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

static void	do_the_sort(int max_a, t_list **stack_a, t_list **stack_b)
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
		situation_two(stack_a, stack_b, bottom_a_value, bottom_b_value);
	else
		situation_three
}

static void	until_find_max(t_list **stack_a, t_list **stack_b, int max_a)
{
	while ((*stack_a)->next)
	{
		if ((*stack_a)->value != max_a)
			return ;
		do_the_sort(max_a, stack_a, stack_b);
	}
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	until_find_max(*stack_a, stack_b, find_max_node(stack_a));
}