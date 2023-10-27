/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/27 21:11:26 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

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

// static void	add_stacka_typeb(t_list **stack_a, t_list **stack_b,
// int ini_pos)
// {
// 	int	bottom_b_value;

// 	while ((*stack_b)->value > (*stack_a)->value)
// 		ft_rrb(stack_b);
// 	bottom_b_value = mv_last(*stack_b)->value;
// 	while ((*stack_a)->value < (*stack_b)->value
// 		&& bottom_b_value > (*stack_a)->value && ft_lstsize(stack_a) > 3)
// 		ft_pb(stack_a, stack_b);
// 	while ((*stack_b)->value != ini_pos)
// 	{
// 		if ((*stack_a)->value > (*stack_a)->next->value)
// 			ft_sa(stack_a);
// 		ft_rr(stack_a, stack_b);
// 	}
// }

// static int	find_median(t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int		target;
// 	int		n;

// 	tmp = *stack_b;
// 	n = 0;
// 	target = ft_lstsize(stack_b) / 2;
// 	while (n < target)
// 	{
// 		tmp = tmp->next;
// 		n++;
// 	}
// 	return (tmp->value);
// }

static int	find_stop_pos(int ini_nbr, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while ((tmp)->value > ini_nbr)
		tmp = tmp->next;
	return ((tmp)->value);
}

void	situation_three_type_b(t_list **stack_a, t_list **stack_b,
		int bottom_a_value, int bottom_b_value)
{
	int	stop_pos;
	int	ini_pos_a;
	int	ini_pos_b;

	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	ini_pos_b = (*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	while ((*stack_b)->value != stop_pos)
	{
		while (ft_lstsize(stack_a) > 3
			&& (*stack_a)->next->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->next->value)
		{
			ft_sa(stack_a);
			ft_pb(stack_a, stack_b);
			bottom_b_value = mv_last(*stack_b)->value;
		}
		ft_rrb(stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value > (*stack_b)->value)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != ini_pos_b)
	{
		if (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	bottom_a_value = 1;
}
