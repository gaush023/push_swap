/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/25 02:40:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

static void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a)
	{
		printf("%d ", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	while (tmp_b)
	{
		printf("%d ", tmp_b->value);
		tmp_b = tmp_b->next;
	}
}

static void	finish_the_sort(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	midle;
	int	max;

	min = (*stack_a)->value;
	midle = (*stack_a)->next->value;
	max = (*stack_a)->next->next->value;
	while (*stack_b && (*stack_b)->value > max)
		ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
	while (*stack_b && (*stack_b)->value > midle)
		ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
	while (*stack_b && (*stack_b)->value > min)
		ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
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
	int		max;

	tmp_a = *stack_a;
	max = find_max_node(*stack_a);
	bottom_a_value = (mv_last(tmp_a))->value;
	if (*stack_b)
	{
		tmp_b = *stack_b;
		bottom_b_value = (mv_last(tmp_b))->value;
	}
	if ((*stack_a)->value < (*stack_a)->next->value)
		ft_sa(stack_a);
	if ((*stack_a)->value == max)
		ft_ra(stack_a);
	else if (!*stack_b || (*stack_a)->value > (*stack_b)->value)
		situation_one(stack_a, stack_b);
	else if ((*stack_a)->value < bottom_b_value)
		situation_two(stack_a, stack_b, bottom_b_value);
	else
		situation_three(stack_a, stack_b, bottom_a_value, bottom_b_value);
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(stack_a) > 3)
	{
		do_the_sort(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		magic_sort_3(stack_a);
	print_stacks(stack_a, stack_b);
	finish_the_sort(stack_a, stack_b);
}
