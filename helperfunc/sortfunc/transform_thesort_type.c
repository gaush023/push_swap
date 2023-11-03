/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_thesort_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 20:22:50 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"


int	quit_thesort_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	max_b;
	int	bottom_b_value;

	max_b = find_max_node(*stack_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_b)->value != max_b)
	{
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	return (1);
}