/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:23:35 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/14 17:04:47 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sign_number(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		flag++;
		str++;
	}
	if (*str || flag == 0)
		return (0);
	return (1);
}

int	check_doubles(int *arr, int n, int nb)
{
	int	i;

	i = 0;
	while (i <= n && arr[i] != nb)
		i++;
	if (i <= n -1)
		return (0);
	return (1);
}

int	check_errors(int n, char *argv[], int *arr)
{
	int		i;
	long	nb;

	i = 0;
	while (i < n)
	{
/* 		if (!is_sign_number(argv[i]))
		{
			ft_putstr("Push Swap Error: negative number\n");
			return (0);
		} */
		nb = ft_atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
		{
			ft_putstr("Push Swap Error: out of limits, like your crush\n");
			return (0);
		}
		if (!check_doubles(arr, i, nb))
		{
			ft_putstr("Push Swap Error: double number\n");
			return (0);
		}
		arr[i++] = nb;
	}
	return (1);
}

int	check_input(int n, char *argv[], int *arr)
{
	if (!check_errors(n, argv, arr))
		return (0);
	return (1);
}
