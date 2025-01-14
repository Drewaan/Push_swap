/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:36:41 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 03:16:04 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct
{
	int				num;
	int				index;
	struct s_struct	*next;
	struct s_struct	*prev;
}	t_list;

// list_utils

t_list	*new_node(int num, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_before(t_list **lst, t_list *new);
void	free_lst(t_list *top);

// ft_split

void	*ft_free(char *str[]);
int		word_count(char *str, char c);
char	*get_word(char *str, char c);
int		ft_strlen(char *str);
char	**ft_split(char *str, char c);

// stack_order_1

void	swap(t_list *node1, t_list *node2, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);

// stack_order_2

t_list	*pop(t_list **head);
void	push(t_list **stack, t_list *node);
void	move_node(t_list **stack_a, t_list **stack_b, char c);

// stack_basic

void	stack_three(t_list **stack);
void	stack_four(t_list **stack_a, t_list **stack_b, int n);
void	stack_five(t_list **stack_a, t_list **stack_b, int n);

// algorithm

int		find_position(t_list *stack, int n);
void	algorithm_b_a(t_list **stack_a, t_list **stack_b, int count);
void	algorithm_a_b(t_list **stack_a, t_list **stack_b, int range, int nb);

// sort_array

int		check_array(int *arr, int n);
int		find_index(int *arr, int n, int num);
void	bubble(int *arr, int n);
int		*copy_array(int *arr, int n);

// input_checker

int		is_sign_number(char *str);
int		check_doubles(int *arr, int n, int num);
int		check_errors(int n, char *argv[], int *arr);
int		check_input(int n, char *argv[], int *arr);

// utils

void	ft_putstr(char *str);
long	ft_atol(char *str);
void	ft_bzero(void *ptr, size_t size);
void	*ft_calloc(size_t count, size_t size);
t_list	*fill_stack(int *arr, int *s_arr, int n);

// range

int		cubic(int n);
int		range(int n);

#endif