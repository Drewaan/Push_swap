/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_order_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:29:20 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 01:46:01 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list *node1, t_list *node2, char c)
{
	int	index;
	int	num;

	index = node1 -> index;
	node1 -> index = node2 -> index;
	node2 -> index = index;
	num = node1 -> num;
	node1 -> num = node2 -> num;
	node2 -> num = num;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_list **stack, char c)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack)-> prev && !(*stack)-> next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first -> next;
	(*stack)-> prev = NULL;
	last -> next = first;
	first -> prev = last;
	first -> next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*last;
	t_list	*second_last;

	if (!(*stack)-> prev && !(*stack)-> next)
		return ;
	last = ft_lstlast(*stack);
	second_last = last -> prev;
	if (second_last != NULL)
		second_last -> next = NULL;
	last -> prev = NULL;
	last -> next = *stack;
	(*stack)-> prev = last;
	*stack = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
