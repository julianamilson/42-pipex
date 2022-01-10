/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treating_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:01:17 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/10 16:48:44 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*what_cmd(char *cmd)
{
	char	**pathways;
	char	*path_cmd;

	printf("what_cmd was called!!\n");
	pathways = ft_split(PATH, ':');
	while (*pathways != NULL)
	{
		printf("%s\n", *pathways);
		path_cmd = ft_strjoin(*pathways, cmd);
		printf("%s\n", path_cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		pathways++;
	}
	return (NULL);
}
