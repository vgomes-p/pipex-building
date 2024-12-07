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

//function 05
int	open_file(char *fname, int flags)
{
	int	fd;

	fd = open(fname, flags, 0777);
	if (fd == -1)
		errorexit();
	return (fd);
}

//function 06
void	low_process(char **argv, char **envar, int *fd)
{
	int		infile;

	if (access(argv[1], F_OK) == -1)
	{
		ft_putstr_fd("Error: Input file does not exit or is inaccessible. \n",
			2);
		errorexit();
	}
	infile = open_file(argv[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(fd[0]);
	execmd(argv[2], envar);
}

//function 07
void	upper_process(char **argv, char **envar, int *fd)
{
	int		outfile;

	outfile = open_file(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execmd(argv[3], envar);
}

//function 08
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
	g_lppid = lppid;
	if (lppid == 0)
		low_process(argv, envar, fd);
	signal(SIGALRM, handle_timeout);
	alarm(5);
	if (waitpid(lppid, NULL, WNOHANG) == -1)
	{
		ft_putstr_fd("Error: waitpid failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	alarm(0);
	upper_process(argv, envar, fd);
	return (0);
}
