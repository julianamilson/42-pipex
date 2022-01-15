/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:00:15 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/14 13:25:04 by jmilson-         ###   ########.fr       */
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
	check_dup_sec(fd[0], STDIN_FILENO, matrix);
	check_dup_sec(outfile, STDOUT_FILENO, matrix);
	close(fd[1]);
	if (pipet->result == 1)
		msg(pipet->output, ": No such file or directory\n", 1, matrix);
	pipet->smod = what_cmd(matrix[0]);
	if (pipet->smod == NULL)
		msg(matrix[0], ": command not found\n", 127, matrix);
	else
		execve(pipet->smod, matrix, pipet->env);
}

void	first_cmd(t_pipex *pipet, int *fd)
{
	char	**matrix;
	int		i;

	treating_cmd(pipet->fcmd);
	matrix = ft_split(pipet->fcmd, ' ');
	pipet->infile = open(pipet->input, O_RDONLY);
	if (pipet->infile < 0)
		msg(pipet->input,
			": No such file or directory OR permission denied.\n", 1, matrix);
	i = 1;
	while (matrix[i])
	{
		original_cmd(matrix[i]);
		matrix[i] = no_quotes(matrix[i]);
		i++;
	}
	check_dup(pipet->infile, STDIN_FILENO);
	check_dup(fd[1], STDOUT_FILENO);
	close(fd[0]);
	pipet->fmod = what_cmd(matrix[0]);
	if (pipet->fmod == NULL)
		msg(matrix[0], ": command not found\n", 127, matrix);
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
		write(2, "Process error\n", 15);
		exit(1);
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
	pipex(&pipet);
	return (pipet.result);
}
