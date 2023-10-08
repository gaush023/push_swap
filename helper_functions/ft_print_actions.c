/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:49:09 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/05 19:44:17 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	ft_print_actions(int n)
{
	if (1 == n)
		return (write(0, "pa\n", 3));
	else if (2 == n)
		return (write(0, "pb\n", 3));
	else if (3 == n)
		return (write(0, "ra\n", 3));
	else if (4 == n)
		return (write(0, "rb\n", 3));
	else if (5 == n)
		return (write(0, "rr\n", 3));
	else if (6 == n)
		return (write(0, "rra\n", 4));
	else if (7 == n)
		return (write(0, "rrb\n", 4));
	else if (8 == n)
		return (write(0, "rrr\n", 4));
	else if (9 == n)
		return (write(0, "sa\n", 3));
	else if (10 == n)
		return (write(0, "sb\n", 3));
	else if (11 == n)
		return (write(0, "ss\n", 3));
	if (-1 == n)
		return (write(0, "Error\n", 6));
}
