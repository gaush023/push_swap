/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stackA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:03:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/19 23:13:26 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

int	is_sorted_stack_a(t_list **stack_a)
{
	int	n;

	n = 0;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			while ((*stack_a)->value < (*stack_a)->next->value)
				stack_a = (*stack_a)->next;
		else if ((*stack_a)->value > (*stack_a)->next->value)
			while ((*stack_a)->value > (*stack_a)->next->value)
				stack_a = (*stack_a)->next;
		n++;
		if (n > 2)
			return (n);
	}
	return (n);
}
