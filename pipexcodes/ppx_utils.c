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

/* Function that will look for the path line inside the environment, will
 split and test each command path and then return the right one. */
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		cnt;
	char	*part_path;

	cnt = 0;
	while (ft_strnstr(envp[cnt], "PATH", 4) == 0)
		cnt++;
	paths = ft_split(envp[cnt] + 5, ':');
	cnt = 0;
	while (paths[cnt])
	{
		part_path = ft_strjoin(paths[cnt], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		cnt++;
	}
	cnt = -1;
	while (paths[++cnt])
		free(paths[cnt]);
	free(paths);
	return (0);
}

/* A simple error displaying function. */
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

/* Function that take the command and send it to find_path
 before executing it. */
void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		ind;
	char	*path;

	ind = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++ind])
			free(cmd[ind]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}

/* Function that will read input from the terminal and return line. */
int	get_next_line(char **line)
{
	char	*buff;
	int		cnt0;
	int		cnt1;
	char	ch;

	cnt0 = 0;
	cnt1 = 0;
	buff = (char *)malloc(10000);
	if (!buff)
		return (-1);
	cnt1 = read(0, &ch, 1);
	while (cnt1 && ch != '\n' && ch != '\0')
	{
		if (ch != '\n' && ch != '\0')
			buff[cnt0] = ch;
		cnt0++;
		cnt1 = read(0, &ch, 1);
	}
	buff[cnt0] = '\n';
	buff[++cnt0] = '\0';
	*line = buff;
	free(buff);
	return (cnt1);
}
