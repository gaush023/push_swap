/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/29 19:39:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

static void	add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_topos)
{
	int	bottom_b_value;

	while ((*stack_a)->value < (*stack_b)->value)
		ft_rrb(stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != back_topos)
	{
		ft_rr(stack_a, stack_b);
	}
}

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
	while ((*stack_b)->value != stop_pos)
	{
		ft_rrb(stack_b);
	}
	bottom_b_value = mv_last(*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != ini_pos_b)
	{
		if ((*stack_a)->value < (*stack_b)->value
			&& (*stack_a)->value > ini_pos_a)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	bottom_a_value = 1;
}
