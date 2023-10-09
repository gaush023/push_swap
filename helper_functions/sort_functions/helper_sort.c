/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:50:14 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/10 00:15:37 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

int	find_max_node(t_list *stacks)
{
	int	max;

	max = stacks->value;
	stacks = stacks->next;
	while (stacks)
	{
		if (max < stacks->value)
			max = stacks->value;
		stacks = stacks->next;
	}
	return (max);
}

int	find_min_node(t_list *stacks)
{
	int	min;

	min = stacks->value;
	stacks = stacks->next;
	while (stacks)
	{
		if (min > stacks->value)
			min = stacks->value;
		stacks = stacks->next;
	}
	return (min);
}
