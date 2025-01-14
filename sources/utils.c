/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:28:39 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:31:55 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

long	ft_atol(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_bzero(void *ptr, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (size > 0)
	{
		*str = '\0';
		str++;
		size--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

t_list	*fill_stack(int *arr, int *s_arr, int n)
{
	int		i;
	t_list	*stack;
	t_list	*node;

	i = 0;
	stack = NULL;
	while (i < n)
	{
		node = new_node(arr[i], find_index(s_arr, n, arr[i]));
		if (!node)
		{
			free_lst(stack);
			return (NULL);
		}
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}
