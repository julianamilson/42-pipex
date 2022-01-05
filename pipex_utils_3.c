/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:27 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/05 13:33:06 by jmilson-         ###   ########.fr       */
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
		sub = (char *)ft_calloc(len + 1, sizeof(char));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	else
		sub = ft_calloc(1, 1);
	return (sub);
}
