/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/30 17:30:14 by sagemura         ###   ########.fr       */
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

static void	add_stacka_typea(t_list **stack_a, t_list **stack_b, int back_pos,
		int median)
{
	int	bottom_b_value;
	// int	n;
	// int	n2;

	// print_stacks(stack_a, stack_b);
	// printf("%d\n", back_pos);
	// printf("stack_a: %d\n", (*stack_a)->value);
	// n = (*stack_a)->value;
	// n2 = (*stack_b)->value;
	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_a)->value > bottom_b_value)
	{
		ft_rrb(stack_b);
		// n++;
		// if (n > 20)
		// {
		// 	(printf("error\n"));
		// 	return ;
		// print_stacks(stack_a, stack_b);
		// printf("bottom_b_value: %d\n", bottom_b_value);
		// printf("%d\n", n);
		// printf("%d\n", n2);
		// printf("%d\n", median);
		// printf("\n===========\n");
		bottom_b_value = mv_last(*stack_b)->value;	
	}
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	while ((*stack_b)->value != back_pos)
	{
		ft_rr(stack_a, stack_b);
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typea(stack_a, stack_b, (*stack_b)->value, median);
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
	median = find_median(stack_b);
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
			add_stacka_typea(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = (*stack_b)->value;
	}
}
