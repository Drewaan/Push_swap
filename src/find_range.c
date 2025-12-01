/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:03:23 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	cubic_root(int n)
{
	int	i;

	i = 0;
	while (i * i * i <= n)
		i++;
	if (n - (i - 1) * (i - 1) * (i - 1) < i * i * i - n)
		return (i - 1);
	else
		return (i);
}

int	find_range(int n)
{
	return (1 + 3 * (cubic_root(n - 1)));
}
