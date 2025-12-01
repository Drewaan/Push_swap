/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_atob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:58:16 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:55:54 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algoritm_atob(t_list **stacka, t_list **stackb, int range, int n)
{
	int	count;

	count = 0;
	while (*stacka)
	{
		if ((*stacka)->index <= count)
		{
			stack_movenode(stacka, stackb, 'b');
			n--;
			count++;
			stack_rotate(stackb, 'b');
		}
		else if ((*stacka)->index <= count + range)
		{
			stack_movenode(stacka, stackb, 'b');
			n--;
			count++;
		}
		else
			stack_rotate(stacka, 'a');
	}
	algoritm_btoa(stacka, stackb, count);
}

int	stack_find_pos(t_list *stack, int num)
{
	int	pos;

	pos = 0;
	while (stack->index != num)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	algoritm_btoa(t_list **stacka, t_list **stackb, int count)
{
	while (count > 0)
	{
		if (stack_find_pos(*stackb, count - 1) <= count / 2)
		{
			while ((*stackb)->index != count - 1)
				stack_rotate(stackb, 'b');
			stack_movenode(stackb, stacka, 'a');
		}
		else
		{
			while ((*stackb)->index != count - 1)
				stack_reverse_rotate(stackb, 'b');
			stack_movenode(stackb, stacka, 'a');
		}
		count--;
	}
}
