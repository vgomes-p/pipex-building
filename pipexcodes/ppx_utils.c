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
	while (ft_strnstr(envar[ind], "PATH", 4) == 0)
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
void	ft_free_split(char **split)
{
	int	ind;

	ind = 0;
	while (split[ind])
	{
		free(split[ind]);
		ind++;
	}
	free(split);
}

//function 03
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
		ft_free_split(cmd);
		errorexit();
	}
	if (execve(finpath, cmd, envar) == -1)
	{
		ft_free_split(cmd);
		errorexit();
	}
}

//function 04
void	print_usage(void)
{
	ft_putstr_fd("\033[31mError: Incorrect number of arguments.\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
}
