/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:16:16 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/21 18:29:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_functions.h"

void	execute_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	printf("execute_sort\n");
	i = ft_lstsize(stack_a);
	printf("i = %d\n", i);
	printf("aaaaaaaaaaa");
	if (i < 4)
	{
		magic_sort_3(stack_a);
	}
	else
	{
		printf("bbbbbbbbbbbbbbbbbbb");
		sort_bigstacks(stack_a, stack_b);
	}
}
