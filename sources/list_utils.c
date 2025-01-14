/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:06:04 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:11:47 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*new_node(int num, int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> num = num;
	new -> index = index;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	lastnode = ft_lstlast(*lst);
	if (!lastnode)
		*lst = new;
	else
	{
		lastnode -> next = new;
		new -> prev = lastnode;
	}
}

void	ft_lstadd_before(t_list **lst, t_list *new)
{
	new -> next = *lst;
	new -> prev = NULL;
	if (!lst)
		(*lst)-> prev = new;
	*lst = new;
}

void	free_lst(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head -> next;
		free(temp);
	}
}
