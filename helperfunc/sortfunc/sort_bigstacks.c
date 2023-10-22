/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:31:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static void	finish_the_sort(t_list **stack_a, t_list **stack_b)
{
	int	bottom_a_value;

	bottom_a_value = (mv_last(*stack_a))->value;
	while (*stack_b && (*stack_b)->value > bottom_a_value)
		ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
	if (*stack_b)
		finish_the_sort(stack_a, stack_b);
	while ((*stack_a)->value != find_min_node(*stack_a))
		ft_rra(stack_a);
}

static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		ft_pb(stack_a, stack_b);
	else if ((*stack_a)->value < (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else
		ft_pb(stack_a, stack_b);
}

static void	do_the_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		bottom_a_value;
	int		bottom_b_value;

	tmp_a = *stack_a;
	bottom_a_value = (mv_last(tmp_a))->value;
	if (*stack_b)
	{
		tmp_b = *stack_b;
		bottom_b_value = (mv_last(tmp_b))->value;
	}
	if (!*stack_b || (*stack_a)->value > (*stack_b)->value)
		situation_one(stack_a, stack_b);
	else if ((*stack_a)->value < bottom_b_value)
		situation_two(stack_a, stack_b, bottom_b_value);
	else
		situation_three(stack_a, stack_b, bottom_a_value, bottom_b_value);
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(stack_a) > 3)
		do_the_sort(stack_a, stack_b);
	magic_sort_3(stack_a);
	finish_the_sort(stack_a, stack_b);
}
