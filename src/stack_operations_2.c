/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:09:55 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_movenode(t_list **stacka, t_list **stackb, char ch)
{
	t_list	*node;

	node = stack_pop(stacka);
	stack_push(stackb, node);
	if (ch == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
