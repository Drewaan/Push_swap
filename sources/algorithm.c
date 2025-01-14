/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:52:23 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:49:34 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_position(t_list *stack, int n)
{
	int	pos;

	pos = 0;
	while (stack -> index != n)
	{
		pos++;
		stack = stack -> next;
	}
	return (pos);
}

void	algorithm_b_a(t_list **stack_a, t_list **stack_b, int count)
{
	while (count > 0)
	{
		if (find_position(*stack_b, count - 1) <= count / 2)
		{
			while ((*stack_b)-> index != count -1)
				rotate(stack_b, 'b');
			move_node(stack_b, stack_a, 'a');
		}
		else
		{
			while ((*stack_b)-> index != count -1)
				reverse_rotate(stack_b, 'b');
			move_node(stack_b, stack_a, 'a');
		}
		count--;
	}
}

void	algorithm_a_b(t_list **stack_a, t_list **stack_b, int range, int nb)
{
	int	count;

	count = 0;
	while (*stack_a)
	{
		if ((*stack_a)-> index <= count)
		{
			move_node(stack_a, stack_b, 'b');
			nb--;
			count++;
			rotate(stack_b, 'b');
		}
		else if ((*stack_a)-> index <= count + range)
		{
			move_node(stack_a, stack_b, 'b');
			nb--;
			count++;
		}
		else
			rotate(stack_a, 'a');
	}
	algorithm_b_a(stack_a, stack_b, count);
}
