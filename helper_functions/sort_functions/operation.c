/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:54:00 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/19 17:13:43 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	ft_sa(t_list **stack_a)
{
	t_list	*second;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	second = *stack_a;
	*stack_a = (*stack_a)->next;
	second->next = (*stack_a)->next;
	(*stack_a)->next = second;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	t_list	*second;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	second = *stack_b;
	*stack_b = (*stack_b)->next;
	second->next = (*stack_b)->next;
	(*stack_b)->next = second;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*second;

	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	second = *stack_a;
	*stack_a = (*stack_a)->next;
	second->next = (*stack_a)->next;
	(*stack_a)->next = second;
	second = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->next = second;
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	write(1, "pb\n", 3);
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
