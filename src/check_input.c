/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:00:41 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sign_num(char *s)
{
	int	flag_num;

	flag_num = 0;
	if (*s == '-')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		flag_num++;
		s++;
	}
	if (*s || flag_num == 0)
		return (0);
	return (1);
}

static int	check_doubles(int *arr, int n, int num)
{
	int	i;

	i = 0;
	while (i <= n && arr[i] != num)
		i++;
	if (i <= n - 1)
		return (0);
	return (1);
}

int	check_errors(int n, char *argv[], int *arr)
{
	int		i;
	long	num;

	i = 0;
	while (i < n)
	{
		if (!is_sign_num(argv[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		num = ft_atol(argv[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (!check_doubles(arr, i, num))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		arr[i++] = num;
	}
	return (1);
}

int	check_input(int n, char *argv[], int *arr)
{
	if (!check_errors(n, argv, arr))
		return (0);
	return (1);
}
