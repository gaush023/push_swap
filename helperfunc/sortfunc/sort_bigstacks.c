/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigstacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:51:11 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/30 21:41:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

// static int	is_reverse_sorted(t_list **stack)
// {
// 	t_list	*head;

// 	head = *stack;
// 	while (head && head->next)
// 	{
// 		if (head->value < head->next->value)
// 			return (0);
// 		head = head->next;
// 	}
// 	return (1);
// }

static void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	printf("stack_a: ");
	while (tmp_a)
	{
		printf("%d ", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("\n");
	printf("stack_b: ");
	while (tmp_b)
	{
		printf("%d ", tmp_b->value);
		tmp_b = tmp_b->next;
	}
	printf("\n");
}

static void	finish_the_sort(t_list **stack_a, t_list **stack_b)
{
	int	bottom_a_value;
	int	flag;

	bottom_a_value = mv_last(*stack_a)->value;
	while (bottom_a_value > (*stack_b)->value
		&& (*stack_b)->value > (*stack_a)->value)
	{
		ft_ra(stack_a);
		bottom_a_value = mv_last(*stack_a)->value;
		print_stacks(stack_a, stack_b);
	}
	printf("bottom_a_value: %d\n", bottom_a_value);
	while ((*stack_b)->value < (*stack_a)->value && *stack_b)
	{
		ft_pa(stack_a, stack_b);
	}
	print_stacks(stack_a, stack_b);
	while (bottom_a_value != find_max_node(*stack_a))
	{
		ft_rra(stack_a);
		bottom_a_value = mv_last(*stack_a)->value;
	}
	if (!*stack_b)
		return ;
	if (ft_lstsize(stack_a) < ft_lstsize(stack_b))
		flag = 1;
	else
		flag = 0;
	print_stacks(stack_a, stack_b);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
	if (is_sorted(stack_a))
		return ;
	if (flag == 1)
	{
		while (bottom_a_value != find_max_node(*stack_a))
		{
			ft_rra(stack_a);
			bottom_a_value = mv_last(*stack_a)->value;
		}
	}
	else
	{
		while (bottom_a_value != find_max_node(*stack_a))
		{
			ft_ra(stack_a);
			bottom_a_value = mv_last(*stack_a)->value;
		}
	}
}

static void	situation_one(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_b)
		ft_pb(stack_a, stack_b);
	else if (ft_lstsize(stack_a) > 3)
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
	{
		// printf("\n=============\nsituation_one\n=============\n");
		situation_one(stack_a, stack_b);
	}
	else if ((*stack_a)->value < bottom_b_value)
	{
		// printf("\n=============\nsituation_two\n=============\n");
		situation_two(stack_a, stack_b, bottom_b_value);
	}
	else
	{
		// printf("\n=============\nsituation_three\n=============\n");
		situation_three(stack_a, stack_b, bottom_a_value, bottom_b_value);
	}
}

void	sort_bigstacks(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(stack_a) > 3)
	{
		do_the_sort(stack_a, stack_b);
		// if (!is_reverse_sorted(stack_b))
		// 	return (print_stacks(stack_a, stack_b));
	}
	if (!is_sorted(stack_a))
		magic_sort_3(stack_a);
	print_stacks(stack_a, stack_b);
	finish_the_sort(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
}
