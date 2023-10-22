/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   situation_three_type_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:38:54 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/22 20:31:13 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sortfunc.h"
#include <stdio.h>

static int	find_stop_pos(int ini_nbr, t_list **stack_b) {
  t_list *tmp;

  tmp = *stack_b;
  while ((tmp)->value > ini_nbr)
    tmp = tmp->next;
  return ((tmp)->value);
}

void	situation_three_type_a(t_list **stack_a, t_list **stack_b) {
  int stop_pos;
  int ini_stackb_node;
  int stackb_bottom;

  stop_pos = find_stop_pos((*stack_a)->value, stack_b);
  ini_stackb_node = (*stack_b)->value;
  ft_pb(stack_a, stack_b);
  while ((*stack_b)->next->value != stop_pos) {
    if ((*stack_a)->value > (*stack_a)->next->value)
      ft_ss(stack_a, stack_b);
    else
      ft_sb(stack_b);
    ft_rr(stack_a, stack_b);
  }
  stackb_bottom = ini_stackb_node;
  while (ini_stackb_node != (*stack_b)->value) {
    stackb_bottom = mv_last(*stack_b)->value;
    if (ft_lstsize(stack_a) > 3 && (*stack_a)->value > (*stack_b)->value &&
        (*stack_a)->value < stackb_bottom)
      ft_pb(stack_a, stack_b);
    ft_rrb(stack_b);
  }
}
