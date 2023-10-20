/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:40:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/20 00:44:41 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

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

void	situation_three(t_list **stack_a, t_list **stack_b, int bottom_b_value,
		int bottom_a_value)
{
	if (find_insertion_pos((*stack_a)->value, stack_b) > ft_lstsize(stack_b)
		/ 2)
    {
        
    }
    else
    {
        
    }
}
