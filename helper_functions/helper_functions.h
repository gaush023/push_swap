/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:03:03 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/09 23:42:46 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

# include "../list.h"
# include "../push_swap.h"
# include "libft/libft.h"

int		ft_check_argc(int argc, char **argv);
int		ft_print_actions(int n);
int		ft_print_error(void);
void	ft_set_head_node(t_list **stack);
t_list	*ft_lstnew(int value);
void	ft_lstadd_back(t_list **stack, t_list *new);
int		is_sorted(t_list **stack);
t_list	*mv_lsat(t_list *head);
void	free_stack(t_list **stack);
void	free_split(char **args);
int	ft_lstsize(t_list *stack);

#endif
