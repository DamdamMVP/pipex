/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalebran <dalebran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:27:18 by dalebran          #+#    #+#             */
/*   Updated: 2023/10/18 10:41:25 by dalebran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*next_word(char **str, char c)
{
	char	*start;
	char	*end;

	while (**str && **str == c)
		(*str)++;
	start = *str;
	while (**str && **str != c)
		(*str)++;
	end = *str;
	return (ft_substr(start, 0, end - start));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	char	*tmp_s;

	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	tmp_s = (char *)s;
	while (i < count_words(s, c))
		result[i++] = next_word(&tmp_s, c);
	result[i] = NULL;
	return (result);
}
