/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:58:22 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:55:32 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;


int		check_input(int n, char *argv[], int *arr);
int		find_index(int *arr, int n, int num);
int		*copy_sort_arr(int *arr, int n);
int		check_sort(int *arr, int n);
int		count_words(char *s, char c);
char	**ft_split(char *s, char c);
long	ft_atol(char *s);

t_list	*create_node(int num, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_before(t_list **lst, t_list *new);
void	free_list(t_list *head);

t_list	*fill_stack(int *arr, int *sortarr, int n);
void	stack_push(t_list **stack, t_list *node);
void	stack_rotate(t_list **stack, char ch);
void	stack_reverse_rotate(t_list **stack, char ch);
void	stack_swap(t_list *node1, t_list *node2, char ch);
t_list	*stack_pop(t_list **head);
void	stack_movenode(t_list **stacka, t_list **stackb, char ch);

void	algoritm_atob(t_list **stacka, t_list **stackb, int n, int count);
void	algoritm_btoa(t_list **stacka, t_list **stackb, int count);
void	stack_sort_three(t_list **stack);
void	stack_sort_four(t_list **stacka, t_list **stackb, int n);
void	stack_sort_five(t_list **stacka, t_list **stackb, int n);
int		stack_find_pos(t_list *stack, int num);
void	direction_to_rotate(t_list **stacka, int n, int range);

void	*ft_calloc(size_t count, size_t size);
void	*ft_free(char *arr[]);
int		find_range(int n);

#endif