/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:23:37 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:27:39 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_sort(t_list **stack_a, int n)
{
	t_list	*stack_b;
	int		distance;

	stack_b = NULL;
	if (n > 5)
		distance = range(n);
	if (n == 5)
		distance = 1;
	if (n == 2)
		swap(*stack_a, (*stack_a)-> next, 'a');
	else if (n == 3)
		stack_three(stack_a);
	else if (n == 4)
		stack_four(stack_a, &stack_b, n);
	else if (n == 5 || n == 6)
		stack_five(stack_a, &stack_b, n);
	else
		algorithm_a_b(stack_a, &stack_b, distance, n);
}

static int	create_stack_a(int n, int *arr)
{
	int		*s_arr;
	t_list	*stack_a;

	s_arr = copy_array(arr, n);
	if (!s_arr)
		return (-1);
	if (n == 1 || check_array(arr, n))
	{
		free(s_arr);
		return (0);
	}
	stack_a = fill_stack(arr, s_arr, n);
	free(s_arr);
	if (!stack_a)
		return (-1);
	choose_sort(&stack_a, n);
	free_lst(stack_a);
	return (0);
}

static int	check_str(char *argv[], int *arr, int n)
{
	char	**split_arr;

	split_arr = ft_split(argv[1], ' ');
	if (!split_arr)
		return (0);
	if (!check_input(n, split_arr, arr))
	{
		ft_free(split_arr);
		return (0);
	}
	if (create_stack_a(n, arr) == -1)
		return (0);
	ft_free(split_arr);
	return (1);
}

static int	check(int argc, char *argv[], int *arr, int n)
{
	char	**split_arr;

	if (argc == 2)
	{
		split_arr = ft_split(argv[1], ' ');
		if (!split_arr)
			return (0);
		if (!check_input(n, split_arr, arr))
		{
			ft_free(split_arr);
			return (0);
		}
	}
	if (argc > 2 && !check_input(n, &argv[1], arr))
		return (0);
	if (create_stack_a(n, arr) == -1)
		return (0);
	return (1);
}

int	main (int argc, char *argv[])
{
	int	n;
	int	*arr;

	if (argc >= 2)
	{
		if (argc == 2)
			n = word_count(argv[1], ' ');
		else
			n = argc - 1;
		arr = (int *)ft_calloc(sizeof(int), n);
		if (!arr)
			return (0);
		if (argc == 2)
			check_str(argv, arr, n);
		else
			check(argc, argv, arr, n);
		free(arr);
	}
	return (0);
}
