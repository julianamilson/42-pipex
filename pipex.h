/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:11:46 by jmilson-          #+#    #+#             */
/*   Updated: 2022/01/12 15:33:32 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# define PATH "/usr/local/sbin/::/usr/local/bin/:\
/usr/sbin/:/usr/bin/:/sbin/:/bin/"

typedef struct s_pipex
{
	char	*input;
	char	*output;
	int		fd;
	char	**env;
	char	*fcmd;
	char	*scmd;
	char	*fmod;
	char	*smod;
	int		result;
	int		infile;
}	t_pipex;

char	*what_cmd(char *cmd);
void	second_cmd(t_pipex *pipet, int *fd);
void	first_cmd(t_pipex *pipet, int *fd);
void	pipex(t_pipex *pipet);
char	*original_cmd(char *cmd);
char	*treating_cmd(char *cmd);
void	msg(char *cmd, char *message, int n);
char	*no_quotes(char *cmd);

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t number, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
