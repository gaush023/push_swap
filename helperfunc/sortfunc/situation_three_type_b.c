/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 19:34:22 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

// static void	print_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*tmp_a;
// 	t_list	*tmp_b;

// 	tmp_a = *stack_a;
// 	tmp_b = *stack_b;
// 	printf("stack_a: ");
// 	while (tmp_a)
// 	{
// 		printf("%d ", tmp_a->value);
// 		tmp_a = tmp_a->next;
// 	}
// 	printf("\n");
// 	printf("stack_b: ");
// 	while (tmp_b)
// 	{
// 		printf("%d ", tmp_b->value);
// 		tmp_b = tmp_b->next;
// 	}
// 	printf("\n");
// }

// static int	front_size(t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int		n;

// 	tmp = *stack_b;
// 	n = 0;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		if (tmp->value > tmp->next->value)
// 			break ;
// 		n++;
// 	}
// 	return (n);
// }

// static int	back_size(t_list **stack_b)
// {
// 	t_list	*tmp;
// 	int		n;

// 	tmp = *stack_b;
// 	n = 0;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		if (tmp->value > tmp->next->value)
// 			break ;
// 	}
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		if (tmp->value > tmp->next->value)
// 			break ;
// 		n++;
// 	}
// 	return (n);
// }

static int	front_size(t_list **stack_b)
{
	t_list	*tmp;
	int		n;

	tmp = *stack_b;
	n = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
		n++;
	}
	return (n);
}

static int	back_size(t_list **stack_b)
{
	t_list	*tmp;
	int		back_size;

	tmp = *stack_b;
	back_size = 0;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	// printf("\n+++++++++++\n");
	// print_stack(stack_b);
	// if (tmp)
	// printf("%d\n", tmp->value);
	if (tmp->next)
		tmp = tmp->next;
	else
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			break ;
		tmp = tmp->next;
		back_size++;
	}
	// printf("%d\n", tmp->value);
	return (back_size);
}

static int	quit_thesort_typea(t_list **stack_a, t_list **stack_b)
{
	int	max_b;

	// printf("AAAAAAAAAAAA\n");
	max_b = find_max_node(*stack_b);
	// printf("%d", max_b);
	while ((*stack_b)->value != max_b)
	{
		ft_rrr(stack_a, stack_b);
		// printf("AAAAAAAAAAA\n");
	}
	return (1);
}

static int	add_stacka_typeb(t_list **stack_a, t_list **stack_b, int back_pos,
		int median)
{
	int	bottom_b_value;

	// int	n;
	// int	n2;
	// print_stacks(stack_a, stack_b);
	// printf("%d\n", back_top_pos);
	// printf("stack_a: %d\n", (*stack_a)->value);
	// n = (*stack_a)->value;
	// n2 = (*stack_b)->value;
	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_a)->value > bottom_b_value)
	{
		ft_rrb(stack_b);
		// print_stacks(stack_a, stack_b);
		// printf("bottom_b_value: %d\n", bottom_b_value);
		// printf("%d\n", n);
		// printf("%d\n", n2);
		// printf("%d\n", median);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	// print_stacks(stack_a, stack_b);
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	while (ft_lstsize(stack_a) > 3 && (*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) >= back_size(stack_b))
			return (quit_thesort_typea(stack_a, stack_b));
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	return (0);
}

static int	find_median(t_list **stack_b)
{
	t_list	*tmp;
	int		target;
	int		n;

	tmp = *stack_b;
	n = 0;
	target = ft_lstsize(stack_b) / 2;
	while (n < target)
	{
		tmp = tmp->next;
		n++;
	}
	return (tmp->value);
}

static int	find_stop_pos(int ini_nbr, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while ((tmp)->value > ini_nbr)
		tmp = tmp->next;
	return ((tmp)->value);
}

void	situation_three_type_b(t_list **stack_a, t_list **stack_b,
		int bottom_a_value, int bottom_b_value)
{
	int	stop_pos;
	int	ini_pos_a;
	int	ini_pos_b;
	int	median;
	int	flag;

	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	ini_pos_b = (*stack_b)->value;
	median = find_median(stack_b);
	flag = 0;
	while ((*stack_b)->value != stop_pos)
	{
		ft_rrb(stack_b);
	}
	bottom_b_value = mv_last(*stack_b)->value;
	ini_pos_a = (*stack_a)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while ((*stack_b)->value != ini_pos_b)
	{
		if (median > (*stack_a)->value && (*stack_a)->value > (*stack_b)->value)
			flag = add_stacka_typeb(stack_a, stack_b, (*stack_b)->value,
					median);
		if (flag == 1)
			return ;
		ft_rr(stack_a, stack_b);
	}
	bottom_a_value = 1;
}
