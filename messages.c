/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:46:48 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/13 17:55:03 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg(char *cmd, char *message, int n, char **matrix)
{
	int	cmd_len;
	int	msg_len;

	cmd_len = ft_strlen(cmd) + 1;
	msg_len = ft_strlen(message) +1;
	write(2, cmd, cmd_len);
	write(2, message, msg_len);
	free_matrix(matrix);
	exit(n);
}

void	check_dup(int a, int b)
{
	if (dup2(a, b) == -1)
	{
		write(2, "Permission denined.\n", 21);
		exit(1);
	}
	close(a);
}

void	check_dup_sec(int a, int b, char **matrix)
{
	if (dup2(a, b) == -1)
	{
		free_matrix(matrix);
		write(2, "Permission denined.\n", 21);
		exit(1);
	}
	close(a);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}
