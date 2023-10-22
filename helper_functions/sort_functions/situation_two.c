/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 17:07:02 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	situation_two(t_list **stack_a, t_list **stack_b, int bottom_b_value)
{
	int	flag;
	int	initial_pos;

	flag = 0;
	initial_pos = (*stack_b)->value;
	while ((*stack_a)->value < bottom_b_value)
	{
		if (ft_lstsize(stack_a) < 4)
			return ;
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
		if (ft_lstsize(stack_a) < 4)
			return ;
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_sa(stack_a);
		if ((*stack_a)->value > (*stack_b)->value
			&& (*stack_a)->value < bottom_b_value)
			ft_pb(stack_a, stack_b);
		bottom_b_value = (*stack_b)->value;
		ft_rr(stack_a, stack_b);
	}
	printf("situation_two\n");
}
