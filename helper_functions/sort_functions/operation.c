/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:54:00 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/10 03:16:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*bottom;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bottom = *stack_a;
	*stack_a = (*stack_a)->next;
	bottom->next = (*stack_a)->next;
	(*stack_a)->next = bottom;
	write(1, "sa\n", 3);
}

void	ft_ra(t_list **stack_a)
{
	t_list	*bottom;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bottom = *stack_a;
	*stack_a = mv_lsat(*stack_a);
	(*stack_a)->next = bottom;
	*stack_a = bottom->next;
	bottom->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*top;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	i = 0;
    top = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = top;
	while (i > 1)
	{
		top = top->next;
		i--;
	}
	top->next = NULL;
	write(1, "rra\n", 4);
}
