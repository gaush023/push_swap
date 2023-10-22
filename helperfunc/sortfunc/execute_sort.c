/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:16:16 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:31:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"

void	execute_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_lstsize(stack_a);
	if (i < 4)
		magic_sort_3(stack_a);
	else
		sort_bigstacks(stack_a, stack_b);
}
