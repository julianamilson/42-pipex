/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:27 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/13 22:24:19 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len >= slen)
		len = slen - start;
	if (slen >= start)
	{
		sub = ft_calloc(len + 1, sizeof(char));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		sub = ft_calloc(1, 1);
	return (sub);
}

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	lilsize;
	size_t	i;
	size_t	j;

	i = 0;
	lilsize = ft_strlen(little);
	if (lilsize == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j]
			&& little[j] != '\0'
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) + 1;
	ptr = (char *)ft_calloc(len, 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
