/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/11/05 02:47:55 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

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
		ft_pb(stack_a, stack_b);
	while (stop_flag > 0)
	{
		bottom_b_value = (mv_last(*stack_b))->value;
		while (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value
			&& bottom_b_value > (*stack_a)->value)
			ft_pb(stack_a, stack_b);
		if ((*stack_a)->value > median && (*stack_a)->value < (*stack_b)->value)
			flag = add_stacka_typea(stack_a, stack_b, median);
		if (flag == 1)
			return ;
		ft_rrr(stack_a, stack_b);
		stop_flag--;
	}
}
