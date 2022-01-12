/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:15 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/12 16:28:55 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_cmd(t_pipex *pipet, int *fd)
{
	int		outfile;
	char	**matrix;
	int		i;

	treating_cmd(pipet->scmd);
	matrix = ft_split(pipet->scmd, ' ');
	i = 1;
	while (matrix[i])
	{
		original_cmd(matrix[i]);
		matrix[i] = no_quotes(matrix[i]);
		i++;
	}
	outfile = open(pipet->output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	if (pipet->result == 1)
		msg(pipet->output, ": No such file or directory\n", 1);
	pipet->smod = what_cmd(matrix[0]);
	if (pipet->smod == NULL)
		msg(matrix[0], ": command not found\n", 127);
	else
		execve(pipet->smod, matrix, pipet->env);
}

void	first_cmd(t_pipex *pipet, int *fd)
{
	char	**matrix;
	int		i;

	treating_cmd(pipet->fcmd);
	matrix = ft_split(pipet->fcmd, ' ');
	i = 1;
	while (matrix[i])
	{
		original_cmd(matrix[i]);
		matrix[i] = no_quotes(matrix[i]);
		i++;
	}
	if (pipet->infile < 0)
		msg(pipet->input, ": No such file or directory\n", 1);
	dup2(pipet->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	pipet->fmod = what_cmd(matrix[0]);
	if (pipet->fmod == NULL)
		msg(matrix[0], ": command not found\n", 127);
	else
		execve(pipet->fmod, matrix, pipet->env);
}

void	pipex(t_pipex *pipet)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
	{
		pipet->result = 1;
		write(2, "System error\n", 14);
		exit(2);
	}
	pid = fork();
	if (pid == 0)
		first_cmd(pipet, fd);
	close(fd[1]);
	waitpid(pid, NULL, WNOHANG);
	second_cmd(pipet, fd);
	close(fd[0]);
}

static void	init_struct(t_pipex *pipet, char **argv, char **env)
{
	pipet->input = argv[1];
	pipet->fcmd = argv[2];
	pipet->scmd = argv[3];
	pipet->output = argv[4];
	pipet->env = env;
	pipet->result = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipet;

	init_struct(&pipet, argv, env);
	if (argc != 5)
	{
		write(2, "Error\nInvalid number of arguments.\n", 36);
		exit(0);
	}
	pipet.infile = open(pipet.input, O_RDONLY, 0777);
	pipex(&pipet);
	return (pipet.result);
}
