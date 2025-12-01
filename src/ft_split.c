/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:05:58 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/12/01 16:56:11 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && !*(s + 1)))
			count++;
		s++;
	}
	return (count);
}

void	*ft_free(char *arr[])
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*get_word(char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char *) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = get_word(&s[i], c);
			if (!arr[j])
				return (ft_free(arr));
			i += ft_strlen(arr[j]);
			j++;
		}
		if (s[i] != '\0')
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
