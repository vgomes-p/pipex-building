/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_timeout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:12:12 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/07 23:17:15 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_timeout(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	ft_putstr_fd("Error: Process time out.\n", 2);
	exit(EXIT_FAILURE);
}

void	timeout_wait(pid_t lppid)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_timeout;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGALRM, &sa, NULL);
	alarm(5);
	if (waitpid(lppid, NULL, WNOHANG) == -1)
	{
		ft_putstr_fd("Error: waitpid failed. \n", 2);
		exit(EXIT_FAILURE);
	}
	alarm(0);
}
