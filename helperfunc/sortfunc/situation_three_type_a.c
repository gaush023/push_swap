/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:26 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

// static void	print_stack(t_list **stack)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	printf("stack: ");
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->value);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

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
			return (quit_thesort_typea(stack_a, stack_b, median));
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		bottom_b_value = mv_last(*stack_b)->value;
	}
	return (0);
}

static int	quit_thesort_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	max_b;
	int	bottom_b_value;

	// printf("AAAAAAAAAAAA\n");
	max_b = find_max_node(*stack_b);
	// printf("%d", max_b);
	bottom_b_value = mv_last(*stack_b)->value;
	while ((*stack_b)->value != max_b)
	{
		if (bottom_b_value > (*stack_a)->value
			&& (*stack_a)->value > (*stack_b)->value && ft_lstsize(stack_a) > 3)
			add_stacka_typeb(stack_a, stack_b, (*stack_b)->value, median);
		ft_rr(stack_a, stack_b);
		// printf("AAAAAAAAAAA\n");
		bottom_b_value = mv_last(*stack_b)->value;
	}
	return (1);
}

static int	add_stacka_typea(t_list **stack_a, t_list **stack_b, int median)
{
	int	bottom_b_value;
	int	back_pos;

	// print_stacks(stack_a, stack_b);
	// printf("%d\n", back_pos);
	// printf("stack_a: %d\n", (*stack_a)->value);
	bottom_b_value = mv_last(*stack_b)->value;
	back_pos = (*stack_b)->value;
	while ((*stack_a)->value < (*stack_b)->value)
	{
		ft_rb(stack_b);
	}
	// print_stacks(stack_a, stack_b);
	// printf("bottom_b_value: %d\n", bottom_b_value);
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value < bottom_b_value
		&& (*stack_a)->value > (*stack_b)->value)
	{
		ft_pb(stack_a, stack_b);
		// printf("bottom_b_value: %d\n", bottom_b_value);
	}
	while ((*stack_b)->value != back_pos)
	{
		if (front_size(stack_b) <= back_size(stack_b))
			return (quit_thesort_typea(stack_a, stack_b, median));
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			add_stacka_typea(stack_a, stack_b, median);
		ft_rrr(stack_a, stack_b);
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

void	situation_three_type_a(t_list **stack_a, t_list **stack_b,
		int bottom_b_value)
{
	int	stop_pos;
	int	stop_flag;
	int	flag;
	int	median;

	stop_flag = 0;
	stop_pos = find_stop_pos((*stack_a)->value, stack_b);
	median = find_median(stack_b);
	flag = 0;
	while ((*stack_b)->value != stop_pos)
	{
		ft_rb(stack_b);
		stop_flag++;
	}
	bottom_b_value = mv_last(*stack_b)->value;
	while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
		&& bottom_b_value > (*stack_a)->value)
	{
		ft_pb(stack_a, stack_b);
	}
	while (stop_flag > 0)
	{
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			flag = add_stacka_typea(stack_a, stack_b, median);
		// printf("front_size: %d\n", front_size(stack_b));
		// printf("back_size: %d\n", back_size(stack_b));
		// print_stacks(stack_a, stack_b);
		// printf("flag: %d\n", flag);
		if (flag == 1)
			return ;
		bottom_b_value = mv_last(*stack_b)->value;
		ft_rrb(stack_b);
		stop_flag--;
	}
}
