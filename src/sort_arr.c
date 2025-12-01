/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:08:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sort(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_bubble(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*copy_sort_arr(int *arr, int n)
{
	int	*sort_arr;
	int	i;

	sort_arr = (int *)malloc(sizeof(int) * n);
	if (!sort_arr)
		return (0);
	i = 0;
	while (i < n)
	{
		sort_arr[i] = arr[i];
		i++;
	}
	sort_bubble(sort_arr, n);
	return (sort_arr);
}

int	find_index(int *arr, int n, int num)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (i);
}
