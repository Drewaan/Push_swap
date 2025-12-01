/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:10:22 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_sort_three(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	if (a->num > b->num && a->num > c->num)
		stack_rotate(stack, 'a');
	else if (b->num > a->num && b->num > c->num)
		stack_reverse_rotate(stack, 'a');
	a = *stack;
	b = a->next;
	if (a->num > b->num)
		stack_swap(a, b, 'a');
}

void	stack_sort_four(t_list **stacka, t_list **stackb, int n)
{
	if (stack_find_pos(*stacka, 0) <= n / 2)
	{
		while ((*stacka)->index != 0)
			stack_rotate(stacka, 'a');
	}
	else
	{
		while ((*stacka)->index != 0)
			stack_reverse_rotate(stacka, 'a');
	}
	stack_movenode(stacka, stackb, 'b');
	stack_sort_three(stacka);
	stack_movenode(stackb, stacka, 'a');
}

void	stack_sort_five(t_list **stacka, t_list **stackb, int n)
{
	int	i;

	i = 0;
	while (i < n / 2)
	{
		if (stack_find_pos(*stacka, i) <= n / 2)
		{
			while ((*stacka)->index != i)
				stack_rotate(stacka, 'a');
		}
		else
		{
			while ((*stacka)->index != i)
				stack_reverse_rotate(stacka, 'a');
		}
		stack_movenode(stacka, stackb, 'b');
		i++;
	}
	stack_sort_three(stacka);
	while (*stackb)
		stack_movenode(stackb, stacka, 'a');
}
