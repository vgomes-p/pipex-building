/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:35:04 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/04 14:35:04 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//function 00
char	*getcmd_path(char *cmd, char **envar)
{
	char	**cmdpath;
	char	*fullpath;
	int		ind;
	char	*partialpath;

	ind = 0;
	while (envar[ind] && ft_strnstr(envar[ind], "PATH", 5) == 0)
		ind++;
	cmdpath = ft_split(envar[ind] + 5, ':');
	ind = 0;
	while (cmdpath[ind])
	{
		partialpath = ft_strjoin(cmdpath[ind], "/");
		fullpath = ft_strjoin(partialpath, cmd);
		free(partialpath);
		if (access(fullpath, F_OK) == 0)
			return (fullpath);
		free(fullpath);
		ind++;
	}
	ind = -1;
	while (cmdpath[++ind])
		free(cmdpath[ind]);
	free(cmdpath);
	return (0);
}

//function 01
void	errorexit(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

//function 02
void	execmd(char *argv, char **envar)
{
	char	**cmd;
	int		ind;
	char	*finpath;

	ind = -1;
	cmd = ft_split(argv, ' ');
	finpath = getcmd_path(cmd[0], envar);
	if (!finpath)
	{
		ft_putstr_fd("Error: Command not found. \n", 2);
		while (cmd[++ind])
			free(cmd[ind]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (!finpath)
	{
		while (cmd[++ind])
			free(cmd[ind]);
		free(cmd);
		errorexit();
	}
	if (execve(finpath, cmd, envar) == -1)
		errorexit();
}

//function 03
void	print_usage(void)
{
	ft_putstr_fd("\033[31mError: Incorrect number of arguments.\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
}

// global var for low_process pid
pid_t	g_lppid;

g_lppid = 0;

//function 04
void	handle_timeout(int sig)
{
	(void)sig;
	if (g_lppid > 0)
		kill(g_lppid, SIGKILL);
	ft_putstr_fd("Error: Process time out.\n", 2);
	exit(EXIT_FAILURE);
}
