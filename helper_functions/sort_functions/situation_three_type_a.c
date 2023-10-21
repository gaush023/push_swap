/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/21 08:51:52 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	situation_three_type_a(t_list **stack_a, t_list **stack_b)
{
	int	ini_stacka_node;
	int	ini_stackb_node;
	int	stackb_bottom;

	ini_stacka_node = (*stack_a)->value;
	ini_stackb_node = (*stack_b)->value;
	ft_pb(stack_a, stack_b);
	while ((*stack_b)->next->value > ini_stacka_node)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			ft_ss(stack_a, stack_b);
		ft_sb(stack_b);
		ft_rr(stack_a, stack_b);
	}
	stackb_bottom = ini_stackb_node;
	while (ini_stackb_node == (*stack_b)->value)
	{
		stackb_bottom = mv_last(stack_a)->value;
		if ((*stack_a)->value > (*stack_b)->value
			&& (*stack_a)->value < stackb_bottom)
			ft_pb(stack_a, stack_b);
		ft_rrb(stack_b);
	}
}
