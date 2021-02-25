/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:54:37 by mlazzare          #+#    #+#             */
/*   Updated: 2021/01/28 15:00:41 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
	return (count);
}

static int	words_len(const char *s, char c, int i)
{
	int l;

	l = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i++] != c)
		l++;
	return (l);
}

static char	**freetab(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

static char	**fill_arr(int words, const char *s, char c, char **arr)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (k < words)
	{
		j = 0;
		if (!(arr[k] = (char *)malloc(sizeof(char) * (words_len(s, c, i) + 1))))
			return (freetab(arr));
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			arr[k][j++] = s[i++];
		arr[k][j] = '\0';
		k++;
	}
	arr[k] = 0;
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	arr = fill_arr(words, s, c, arr);
	return (arr);
}
