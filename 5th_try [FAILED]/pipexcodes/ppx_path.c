/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:11:08 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/08 01:16:27 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	freethe(char **cmdpath)
{
	int	ind;

	ind = 0;
	while (cmdpath[ind])
	{
		free(cmdpath[ind]);
		ind++;
	}
	free(cmdpath);
}

static char	*findpath(char **envar)
{
	int	ind;

	ind = 0;
	if (!envar)
		return (NULL);
	while (envar[ind])
	{
		if (ft_strncmp(envar[ind], "PATH=", 5) == 0)
			return (envar[ind] + 5);
		ind++;
	}
	return (NULL);
}

static char	*trypath(char *cmd, char *path)
{
	char	*partialpath;
	char	*fullpath;

	partialpath = ft_strjoin(path, "/");
	if (!partialpath)
		return (NULL);
	fullpath = ft_strjoin(partialpath, cmd);
	free(partialpath);
	if (!fullpath)
		return (NULL);
	if (access(fullpath, F_OK) == 0)
		return (fullpath);
	free(fullpath);
	return (NULL);
}

char	*getcmd_path(char *cmd, char **envar)
{
	char	**cmdpath;
	char	*fullpath;
	char	*path_vars;
	int		ind;

	if (!cmd || !envar)
		return (NULL);
	path_vars = findpath(envar);
	if (!path_vars)
		return (NULL);
	cmdpath = ft_split(path_vars, ':');
	if (!cmdpath)
		return (NULL);
	ind = -1;
	while (cmdpath[++ind])
	{
		fullpath = trypath(cmd, cmdpath[ind]);
		if (fullpath)
			return (freethe(cmdpath), fullpath);
	}
	return (freethe(cmdpath), NULL);
}