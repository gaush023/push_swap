/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/05 16:07:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

// static int	is_reverse_sorted(t_list **stack)
// {
// 	t_list	*head;

// 	head = *stack;
// 	while (head && head->next)
// 	{
// 		if (head->value < head->next->value)
// 			return (0);
// 		head = head->next;
// 	}
// 	return (1);
// }

// static void	print_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	printf("stack_a: ");
// 	while (tmp_a)
// 	{
// 		printf("%d ", tmp_a->value);
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("\n");
// 	printf("stack_b: ");
// 	while (tmp_b)
// 	{
// 		printf("%d ", tmp_b->value);
// 		tmp_b = tmp_b->next;
// 	}
// 	printf("\n");
// }

void	situation_two(t_list **stack_a, t_list **stack_b, int bottom_b_value)
{
	int	initial_pos;
	int	ini_pos_a;
	int	bottom_a_value;
	int	median;

	initial_pos = (*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	median = find_median(stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
		ft_pb(stack_a, stack_b);
	bottom_a_value = (mv_last(*stack_a))->value;
	while (ft_lstsize(stack_a) > 3 && bottom_a_value < bottom_b_value
		&& bottom_a_value > (*stack_b)->value)
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		bottom_a_value = (mv_last(*stack_a))->value;
	}
	bottom_b_value = (mv_last(*stack_b))->value;
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->next->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->next->value)
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while (initial_pos != (*stack_b)->value)
	{
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value
			&& ft_lstsize(stack_b) > 3)
			add_stacka_typea(stack_a, stack_b, (*stack_b)->value);
		ft_rr(stack_a, stack_b);
		bottom_b_value = (*stack_b)->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
			&& (*stack_a)->value > (*stack_b)->value)
		{
			ft_pb(stack_a, stack_b);
		}
	}
}
