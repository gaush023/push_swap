/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:52:02 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/14 23:39:49 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FUNCTIONS_H
# define SORT_FUNCTIONS_H

# include "../../push_swap.h"
# include "../helper_functions.h"
# include "../libft/libft.h"

int		find_max_node(t_list *stacks);
int		find_min_node(t_list *stacks);
void	ft_sa(t_list **stack_a);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rra(t_list **stack_a);
void	magic_sort_3(t_list **stack_a);
void	execute_sort(t_list **stack_a, t_list **stack_b);
void	situation_2(t_list **stack_a, t_list **stack_b, int bottom_b_value,
			int bottom_a_value);

#endif