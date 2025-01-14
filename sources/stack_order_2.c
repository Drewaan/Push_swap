/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 02:08:02 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 05:59:58 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*pop(t_list **head)
{
	t_list	*node;

	node = *head;
	if (!node -> prev && !node -> next)
		*head = NULL;
	else
	{
		*head = node -> next;
		if (*head != NULL)
			(*head)-> prev = NULL;
		node -> next = NULL;
	}
	return (node);
}

void	push(t_list **stack, t_list *node)
{
	ft_lstadd_before(stack, node);
}

void	move_node(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*node;

	node = pop(stack_a);
	push(stack_b, node);
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
