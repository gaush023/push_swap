/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:43:50 by sagemura          #+#    #+#             */
/*   Updated: 2023/10/12 21:09:35 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*mv_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (*stack)
	{
		tmp = mv_last(*stack);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	main(void)
{
	t_list *list = NULL;

	// リストにノードを追加
	ft_lstadd_back(&list, 10);
	ft_lstadd_back(&list, 20);
	ft_lstadd_back(&list, 30);

	// 2番目のノードにアクセス
	t_list *second_node = list->next;

	// 2番目のノードのpreメンバを使用して、前のノードのvalueを表示
	if (second_node->pre)
		printf("The value of the previous node is: %d\n",
				second_node->pre->value);
	else
		printf("There is no previous node.\n");

	// メモリの解放
	while (list)
	{
		t_list *temp = list;
		list = list->next;
		free(temp);
	}

	return (0);
}