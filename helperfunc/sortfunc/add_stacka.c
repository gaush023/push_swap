/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stacka_typea.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 20:14:54 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	add_stacka_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	bottom_b_value;
	int	back_pos;

	bottom_b_value = mv_last(*stack_b)->value;
	back_pos = (*stack_b)->value;
	while ((*stack_a)->value < (*stack_b)->value)
	{
		ft_rb(stack_b);
	}
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
		ft_pb(stack_a, stack_b);
	while ((*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) <= back_size(stack_b))
			return (quit_thesort_typea(stack_a, stack_b, median));
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typea(stack_a, stack_b, median);
		ft_rrr(stack_a, stack_b);
	}
	return (0);
}

int	add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_pos,
		int median)
{
	int	bottom_b_value;

	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_a)->value > bottom_b_value)
	{
		ft_rrb(stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
		ft_pb(stack_a, stack_b);
	while (ft_lstsize(stack_a) > 3 && (*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) >= back_size(stack_b))
			return (quit_thesort_typea(stack_a, stack_b, median));
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	return (0);
}


