/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:35:14 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/04 14:35:14 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	low_process(char **argv, char **envar, int *fd)
{
	int		file_inp;

	file_inp = open(argv[1], O_RDONLY, 0777);
	if (file_inp == -1)
		exiterror();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_inp, STDIN_FILENO);
	close(fd[0]);
	execmd(argv[2], envar);
}

void	upper_process(char **argv, char **envar, int *fd)
{
	int		file_outp;

	file_outp = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_outp == -1)
		exiterror();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_outp, STDOUT_FILENO);
	close(fd[1]);
	execmd(argv[3], envar);
}

int	main(int argc, char **argv, char **envar)
{
	int		fd[2];
	pid_t	lppid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exiterror();
		lppid = fork();
		if (lppid == -1)
			exiterror();
		if (lppid == 0)
			low_process(argv, envar, fd);
		waitpid(lppid, NULL, 0);
		parent_process(argv, envar, fd);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Incorrect number of arguments.\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
	}
	return (0);
}
