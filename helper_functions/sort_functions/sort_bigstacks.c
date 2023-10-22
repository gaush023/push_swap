/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 19:41:02 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"
#include <stdio.h>


static void	print_stack(t_list **stack)
{
	t_list	*current_node;

	if (!stack || !*stack)
	{
		printf("Stack is empty.\n");
		return ;
	}
	current_node = *stack;
	while (current_node != NULL)
	{
		printf("%d ", current_node->value);
		current_node = current_node->next;
	}
}
static void	print_stakcs(t_list **stack_a, t_list **stack_b)
{
	printf("stack_a:");
	print_stack(stack_a);
	printf("\n");
	printf("stack_b:");
	print_stack(stack_b);
	printf("\n");
}

static void	finish_the_sort(t_list **stack_a, t_list **stack_b)
{
	int	bottom_a_value;

	bottom_a_value = (mv_last(*stack_a))->value;
	while (*stack_b && (*stack_b)->value > bottom_a_value)
		ft_pa(stack_a, stack_b);
	ft_rra(stack_a);
	print_stack(stack_a);
	printf("\n");
	if (*stack_b)
		finish_the_sort(stack_a, stack_b);
	while ((*stack_a)->value != find_min_node(*stack_a))
		ft_rra(stack_a);
}

static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
	{
		ft_pb(stack_a, stack_b); // Update this line
		printf("situation_one type b\n");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b); // Update this line
		printf("situation_one type a\n");
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

	printf("do_the_sort\n");
	tmp_a = *stack_a;
	bottom_a_value = (mv_last(tmp_a))->value;
	printf("bottom_a_value: %d\n", bottom_a_value);
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
	{
		printf("Stack size before: %d\n", ft_lstsize(stack_a));
		do_the_sort(stack_a, stack_b);
		print_stakcs(stack_a, stack_b);
		printf("Stack size after: %d\n", ft_lstsize(stack_a));
	}
	magic_sort_3(stack_a);
	finish_the_sort(stack_a, stack_b);
}
