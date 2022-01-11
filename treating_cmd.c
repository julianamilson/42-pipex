/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treating_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:01:17 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/11 20:17:08 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*what_cmd(char *cmd)
{
	char	**pathways;
	char	*path_cmd;

	pathways = ft_split(PATH, ':');
	while (*pathways != NULL)
	{
		path_cmd = ft_strjoin(*pathways, cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		pathways++;
	}
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

	i = 0;
	while (cmd[i])
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
