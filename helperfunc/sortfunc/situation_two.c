/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/28 22:00:10 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

// static void	print_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	while (tmp_a)
// 	{
// 		printf("%d ", tmp_a->value);
// 		tmp_a = tmp_a->next;
// 	}
// 	while (tmp_b)
// 	{
// 		printf("%d ", tmp_b->value);
// 		tmp_b = tmp_b->next;
// 	}
// 	printf("\n");
// }
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

static void	add_stacka_typea(t_list **stack_a, t_list **stack_b, int back_topos)
{
	int	bottom_b_value;

	while ((*stack_a)->value < (*stack_b)->value)
		ft_rrb(stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value > (*stack_b)->value)
			ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != back_topos)
	{
		if (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
}

void	situation_two(t_list **stack_a, t_list **stack_b, int bottom_b_value)
{
	int	flag;
	int	initial_pos;
	int	ini_pos_a;
	int	median;

	flag = 0;
	initial_pos = (*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	median = find_median(*stack_a);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value)
	{
		while ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->next->value > (*stack_b)->value)
		{
			ft_sa(stack_a);
			ft_pb(stack_a, stack_b);
		}
		if ((*stack_a)->value < (*stack_b)->value && flag != 0)
			break ;
		ft_pb(stack_a, stack_b);
		flag++;
	}
	while (initial_pos != (*stack_b)->value)
	{
		if (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& (*stack_a)->value < bottom_b_value)
			ft_pb(stack_a, stack_b);
		if ((*stack_a)->value < (*stack_b)->value
			&& (*stack_a)->value > ini_pos_a)
			add_stacka_typea(stack_a, stack_b, (*stack_b)->value);
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a);
		if(median > (*stack_a)->value)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value);
		bottom_b_value = (*stack_b)->value;
		ft_rr(stack_a, stack_b);
	}
}
