/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 02:36:23 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/07 01:34:00 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	malloc_stacks(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = (t_list **)malloc(sizeof(t_list *));
	*stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!*stack_a || !*stack_b)
	{
		free(*stack_a);
		free(*stack_b);
		return (-1);
	}
	return (0);
}

static void	create_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	*args;
	int		i;

	i = 0;
	if (argv == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_set_stacks(*stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		flag;

	if (ft_check_argc(argc, argv) == -1)
		return (ft_print_error());
	if (malloc_stacks(&stack_a, &stack_b) == -1)
		return (ft_print_error());
}
