/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treating_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:01:17 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/14 14:28:01 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*what_cmd(char *cmd)
{
	char	**pathways;
	char	*path_cmd;
	int		i;

	pathways = ft_split(PATH, ':');
	i = 0;
	while (pathways[i])
	{
		path_cmd = ft_strjoin(pathways[i], cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	free(pathways);
	return (NULL);
}

char	*treating_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] != '\'' && cmd[i] != '\0')
			{
				if (cmd[i] == ' ')
					cmd[i] = 1;
				i++;
			}
		}
		i++;
	}
	return (cmd);
}

char	*original_cmd(char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(cmd);
	while (i < j)
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] != '\'' && cmd[i] != '\0')
			{
				if (cmd[i] == 1)
					cmd[i] = ' ';
				i++;
			}
		}
		i++;
	}
	return (cmd);
}

char	*no_quotes(char *cmd)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(cmd) - 1;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			str = ft_calloc(len, sizeof(char));
			while (i < len)
			{
				str[j++] = cmd[i++];
			}
			return (str);
		}
		i++;
	}
	return (cmd);
}
