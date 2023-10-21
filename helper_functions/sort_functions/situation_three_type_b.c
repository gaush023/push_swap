/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/21 17:24:21 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"
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
	int	subject;
	int	ini_pos;

	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	subject = (*stack_a)->value;
	ini_pos = (*stack_b)->value;
	if (bottom_a_value < bottom_b_value)
	{
		ft_rrr(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_sb(stack_a);
	}
	printf("%d", stop_pos);
	while ((*stack_b)->value != stop_pos)
		ft_rrb(stack_b);
	while ((*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	while ((*stack_b)->value != ini_pos)
	{
		if ((*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
}
