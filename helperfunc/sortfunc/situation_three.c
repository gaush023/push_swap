/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:40:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/27 19:44:44 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

int	find_insertion_pos(int i_p, t_list **stack_b)
{
	int		n;
	t_list	*tmp;

	tmp = *stack_b;
	n = 0;
	while (tmp)
	{
		if (tmp->value < i_p)
			return (n);
		tmp = tmp->next;
		n++;
	}
	return (n);
}

void	situation_three(t_list **stack_a, t_list **stack_b, int bottom_a_value,
		int bottom_b_value)
{
	if (find_insertion_pos((*stack_a)->value, stack_b) < ft_lstsize(stack_b)
		/ 2)
		situation_three_type_a(stack_a, stack_b, bottom_b_value);
	else
		situation_three_type_b(stack_a, stack_b, bottom_a_value,
				bottom_b_value);
}
