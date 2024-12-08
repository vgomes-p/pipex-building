/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:25:08 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/08 02:47:59 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *fname, int flags)
{
	int	fd;

	fd = open(fname, flags, 0777);
	if (fd == -1)
		errorexit();
	return (fd);
}

void	low_process(char **argv, char **envar, int *fd)
{
	int		infile;

	infile = open_file(argv[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	signal(SIGPIPE, SIG_DFL);
	execmd(argv[2], envar);
}

void	high_process(char **argv, char **envar, int *fd)
{
	int		outfile;

	outfile = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execmd(argv[3], envar);
}
