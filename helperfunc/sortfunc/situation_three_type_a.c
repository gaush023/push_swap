/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/30 16:58:55 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

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

static void	add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_pos,
		int median)
{
	int	bottom_b_value;

	// print_stacks(stack_a, stack_b);
	// printf("%d\n", back_pos);
	// printf("stack_a: %d\n", (*stack_a)->value);
	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_a)->value < (*stack_b)->value)
	{
		ft_rb(stack_b);
	}
	// print_stacks(stack_a, stack_b);
	// printf("bottom_b_value: %d\n", bottom_b_value);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
		// printf("bottom_b_value: %d\n", bottom_b_value);
	}
	while ((*stack_b)->value != back_pos)
	{
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		// bottom_b_value = mv_last(*stack_b)->value;
		ft_rrr(stack_a, stack_b);
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

static int	find_stop_pos(int ini_nbr, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while ((tmp)->value > ini_nbr)
		tmp = tmp->next;
	return ((tmp)->value);
}

void	situation_three_type_a(t_list **stack_a, t_list **stack_b,
		int bottom_b_value)
{
	int	stop_pos;
	int	stop_flag;
	int	ini_pos_a;
	int	median;

	stop_flag = 0;
	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	median = find_median(stack_b);
	while ((*stack_b)->value != stop_pos)
	{
		ft_rb(stack_b);
		stop_flag++;
	}
	bottom_b_value = mv_last(*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while (stop_flag > 0)
	{
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		bottom_b_value = mv_last(*stack_b)->value;
		// if (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		// 	&& bottom_b_value > (*stack_a)->value)
		// {
		// 	ft_pb(stack_a, stack_b);
		// }
		ft_rrr(stack_a, stack_b);
		stop_flag--;
	}
}
