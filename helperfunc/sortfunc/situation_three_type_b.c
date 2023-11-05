/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/05 15:30:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

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
	int	ini_pos_b;
	int	median;
	int	flag;

	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	ini_pos_b = (*stack_b)->value;
	median = find_median(stack_b);
	flag = 0;
	while ((*stack_b)->value != stop_pos)
	{
		ft_rrb(stack_b);
	}
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3
		&& (*stack_a)->next->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_b)->value)
			ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != ini_pos_b)
	{
		bottom_b_value = mv_last(*stack_b)->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value)
			flag = add_stacka_typeb(stack_a, stack_b, (*stack_b)->value,
					median);
		if (flag == 1)
			return ;
		ft_rr(stack_a, stack_b);
	}
	bottom_a_value = 1;
}
