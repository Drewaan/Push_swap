/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:49:12 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:01:58 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_three(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *stack;
	b = a -> next;
	c = b -> next;
	if (a -> num > b -> num && a -> num > c -> num)
		rotate(stack, 'a');
	else if (b -> num > a -> num && b -> num > c -> num)
		reverse_rotate(stack, 'a');
	a = *stack;
	b = a -> next;
	if (a -> num > b -> num)
		swap(a, b, 'a');
}

void	stack_four(t_list **stack_a, t_list **stack_b, int n)
{
	if (find_position(*stack_a, 0) <= n / 2)
	{
		while ((*stack_a)-> index != 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)-> index != 0)
			reverse_rotate(stack_a, 'a');
	}
	move_node(stack_a, stack_b, 'b');
	stack_three(stack_a);
	move_node(stack_b, stack_a, 'a');
}

void	stack_five(t_list **stack_a, t_list **stack_b, int n)
{
	int	i;

	i = 0;
	while (i < n / 2)
	{
		if (find_position(*stack_a, i) <= n / 2)
		{
			while ((*stack_a)-> index != i)
				rotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)-> index != i)
				reverse_rotate(stack_a, 'a');
		}
		move_node(stack_a, stack_b, 'b');
		i++;
	}
	stack_three(stack_a);
	while (*stack_b)
		move_node(stack_b, stack_a, 'a');
}
