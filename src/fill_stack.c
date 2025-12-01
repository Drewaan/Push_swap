/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:02:50 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*fill_stack(int *arr, int *sortarr, int n)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	stack = NULL;
	i = 0;
	while (i < n)
	{
		node = create_node(arr[i], find_index(sortarr, n, arr[i]));
		if (!node)
		{
			free_list(stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}
