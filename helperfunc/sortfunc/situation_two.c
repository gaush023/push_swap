/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/29 20:35:06 by sagemura         ###   ########.fr       */
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

static void	add_stacka_typea(t_list **stack_a, t_list **stack_b,
		int back_top_pos)
{
	while ((*stack_a)->value > mv_last(*stack_b)->value)
	{
		ft_rrb(stack_b);
	}
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->value < mv_last(*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != back_top_pos)
	{
		ft_rr(stack_a, stack_b);
	}
}

static int	find_median(t_list **stack_b)
{
	t_list	*tmp;
	int		target;
	int		n;

	tmp = *stack_b;
	n = 0;
	target = ft_lstsize(stack_b) / 2;
	while (n < target)
	{
		tmp = tmp->next;
		n++;
	}
	return (tmp->value);
}

void	situation_two(t_list **stack_a, t_list **stack_b, int bottom_b_value)
{
	int	initial_pos;
	int	ini_pos_a;
	int	median;

	initial_pos = (*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	median = find_median(stack_a);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while (initial_pos != (*stack_b)->value)
	{
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value
			&& ft_lstsize(stack_b) > 3)
			add_stacka_typea(stack_a, stack_b, (*stack_b)->value);
		ft_rr(stack_a, stack_b);
		bottom_b_value = (*stack_b)->value;
	}
}
