/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:17:52 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/08 06:39:39 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	word_count(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str != c && *(str + 1) == c) || (*str != c && !*(str + 1)))
			count++;
		str++;
	}
	return (count);
}

char	*get_word(char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char *) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			arr[j] = get_word(&str[i], c);
			if (!arr[j])
				return (ft_free(arr));
			i = i + ft_strlen(arr[j]);
			j++;
		}
		if (str[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
