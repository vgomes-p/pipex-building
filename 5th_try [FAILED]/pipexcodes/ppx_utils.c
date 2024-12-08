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

void	errorexit(void)
{
	perror("\033[31mError![0m");
	exit(EXIT_FAILURE);
}

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
	if (execve(finpath, cmd, envar) == -1)
		errorexit();
}

void	print_usage(void)
{
	ft_putstr_fd("\033[31mError: Incorrect number of arguments.\n\e[0m", 2);
	ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 1);
}
