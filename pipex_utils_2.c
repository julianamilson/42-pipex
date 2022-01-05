/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:30:43 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/05 16:43:01 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_row(char const *s, char c)
{
	size_t	row;
	size_t	i;

	i = 0;
	row = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			row++;
		i++;
	}
	return (row);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	rows;
	size_t	i;
	size_t	k;

	rows = ft_row(s, c);
	split = ft_calloc(sizeof(char *), (rows + 1));
	if (split == NULL)
		return (NULL);
	k = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = ft_words(s, c);
			split[k] = ft_substr(s, 0, i);
			if (!split[k])
				return (NULL);
			s += i;
			k++;
		}
		while (*s && (*s == c))
			s++;
	}
	return (split);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*sr;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	sr = (char *)ft_calloc((len + 1), sizeof(char));
	if (sr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sr[i + j] = s2[j];
		j++;
	}
	free(s1);
	s1 = NULL;
	return (sr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size > len + 1)
		ft_memmove(dest, src, len + 1);
	else if (size != 0)
	{
		ft_memmove(dest, src, size);
		dest[size - 1] = 0;
	}
	return (len);
}
