/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:46:48 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/12 16:48:19 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg(char *cmd, char *message, int n, char **matrix)
{
	int	cmd_len;
	int	msg_len;
	int	i;

	i = 0;
	cmd_len = ft_strlen(cmd) + 1;
	msg_len = ft_strlen(message) +1;
	write(2, cmd, cmd_len);
	write(2, message, msg_len);
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	exit(n);
}
