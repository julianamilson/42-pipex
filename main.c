/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:15 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/05 13:37:56 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_pipex *pipet, int *fd)
{

	pipet->fmod = what_cmd(pipet->fcmd);

}

void	pipex(t_pipex *pipet)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
	{
		printf("deu ruim");
		exit(2);
	}
	pid = fork();
	if (pid == 0)
	{
		first_cmd(pipet, fd);
	}
	second_cmd(pipet, fd);
}

void	define_variables(t_pipex *pipet, char **argv, char **env)
{
	pipet->input = argv[1];
	pipet->fcmd = argv[2];
	pipet->scmd = argv[3];
	pipet->output = argv[4];
	pipet->env = env;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipet;

	define_variables(&pipet, argv, env);
	if (argc != 5)
	{
		printf("Error\nInvalid number of arguments.\n");
		exit(1);
	}
	pipex(&pipet);
	return (0);
}
