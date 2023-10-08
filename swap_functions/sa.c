/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 08:20:41 by sagemura          #+#    #+#             */
/*   Updated: 2023/08/16 10:04:38 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_node **stack_a)
{
	t_node *first;
	t_node *second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (-1);
	first = *stack_a;
	second = (*stack_a)->next;

	first->next = second->next;
	second->next = first;
	*stack_a = second;

	return (0);
}