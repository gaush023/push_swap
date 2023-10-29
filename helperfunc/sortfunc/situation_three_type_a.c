/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/29 19:38:30 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static void	add_stacka_tyea(t_list **stack_a, t_list **stack_b, int back_pos)
{
	int	bottom_b_value;

	while ((*stack_a)->value < (*stack_b)->value)
		ft_rb(stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != back_pos)
	{
		ft_rrr(stack_a, stack_b);
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

void	situation_three_type_a(t_list **stack_a, t_list **stack_b,
		int bottom_b_value)
{
	int	stop_pos;
	int	stop_flag;
	int	ini_pos_a;

	stop_flag = 0;
	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
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
	if (stop_flag > ft_lstsize(stack_b) / 2)
	{
		while ((*stack_b)->value != find_max_node(*stack_b))
		{
			ft_rb(stack_b);
		}
	}
	else
	{
		while (stop_flag > 0)
		{
			if ((*stack_a)->value < (*stack_b)->value
				&& (*stack_a)->value > ini_pos_a)
				add_stacka_tyea(stack_a, stack_b, (*stack_b)->value);
			ft_rrr(stack_a, stack_b);
			bottom_b_value = mv_last(*stack_b)->value;
			stop_flag--;
		}
	}
}
