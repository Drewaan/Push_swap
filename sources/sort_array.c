/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:41:25 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 02:02:02 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_array(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (i);
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

void	bubble(int *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i -1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*copy_array(int *arr, int n)
{
	int	*s_arr;
	int	i;

	s_arr = (int *)malloc(sizeof(int) * n);
	if (!s_arr)
		return (0);
	i = 0;
	while (i < n)
	{
		s_arr[i] = arr[i];
		i++;
	}
	bubble(s_arr, n);
	return (s_arr);
}
