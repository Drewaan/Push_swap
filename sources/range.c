/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:45:39 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/07 16:49:25 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cubic(int n)
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

int	range(int n)
{
	return (1 + 3 * (cubic(n - 1)));
}
