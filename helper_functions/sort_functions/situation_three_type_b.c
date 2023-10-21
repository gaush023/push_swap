/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/21 08:56:36 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	situation_three_type_a(t_list **stack_a, t_list **stack_b,
		int bottom_a_value, int bottom_b_value)
{
	int	subject;

	subject = (*stack_a)->value;
	if (bottom_a_value < bottom_b_value)
	{
		ft_rrr(stack_a, stack_b);
		ft_pb(stack_a, stack_b);
		ft_sb(stack_a);
	}
	ft_pb(stack_a, stack_b);
	while (subject > (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			ft_ss(stack_a, stack_b);
		ft_sb(stack_b);
		ft_rrr(stack_a, stack_b);
	}
}
