/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_stackA.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:03:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/19 23:33:29 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

int	is_sorted_stack_a(t_list **stack_a)
{
	int		n;
	t_list	*current;

	current = *stack_a;
	n = 0;
	while (current && current->next)
	{
		if (current->value < current->next->value)
		{
			while (current->next && current->value < current->next->value)
				current = current->next;
			n++;
		}
		else if (current->value > current->next->value)
		{
			while (current->next && current->value > current->next->value)
				current = current->next;
			n++;
		}
		if (n > 2)
			return (n);
		if (current->next)
			current = current->next;
	}
	return (n);
}
