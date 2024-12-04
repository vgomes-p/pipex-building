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

#include "pipex.h"

void	low_process(char **argv, char **envar, int *fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		errorexit();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execmd(argv[2], envar);
}

void	upper_process(char **argv, char **envar, int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		errorexit();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execmd(argv[3], envar);
}

int	main(int argc, char **argv, char **envar)
{
	int		fd[2];
	pid_t	lppid;

	if (argc != 5)
	{
		print_usage();
		return (1);
	}
	if (pipe(fd) == -1)
		errorexit();
	lppid = fork();
	if (lppid == -1)
		errorexit();
	if (lppid == 0)
		low_process(argv, envar, fd);
	waitpid(lppid, NULL, 0);
	upper_process(argv, envar, fd);
	return (0);
}
