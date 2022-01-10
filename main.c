/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:15 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/07 15:20:10 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_cmd(t_pipex *pipet, int *fd)
{
	int	outfile;
	char	**matrix;

	matrix = ft_split(pipet->scmd, ' ');
	outfile = open(pipet->output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[1], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	pipet->smod = what_cmd(matrix[0]);
	execve(pipet->smod, matrix, pipet->env);
}

void	first_cmd(t_pipex *pipet, int *fd)
{
	int		infile;
	char	**matrix;

	matrix = ft_split(pipet->fcmd, ' ');
	infile = open(pipet->input, O_RDONLY);
	dup2(infile, STDIN_FILENO);
	dup2(fd[0], STDOUT_FILENO);
	close(fd[1]);
	pipet->fmod = what_cmd(matrix[0]);
	execve(pipet->fmod, matrix, pipet->env);
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
	write(2, "1. Tudo ok\n", 12);
	pid = fork();
	if (pid == 0)
		first_cmd(pipet, fd);
	write(2, "2. Tudo ok\n", 12);
	close(fd[1]);
	pid = fork();
	if (pid == 0)
		second_cmd(pipet, fd);
	write(2, "3. Tudo ok\n", 12);
	waitpid(pid, NULL, 0);
	close(fd[0]);
}

static void	init_struct(t_pipex *pipet, char **argv, char **env)
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

	init_struct(&pipet, argv, env);
	if (argc != 5)
	{
		printf("Error\nInvalid number of arguments.\n");
		exit(1);
	}
	pipex(&pipet);
	return (0);
}
