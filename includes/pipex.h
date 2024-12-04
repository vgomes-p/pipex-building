/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:07:08 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/02 22:07:08 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

/* FUNCTIONS ON PIPEX.C */
void	low_process(char **argv, char **envar, int *fd);
void	upper_process(char **argv, char **envar, int *fd);
int		main(int argc, char **argv, char **envar);

/* FUNCTIONS ON PPX_UTILS.C */
char	*ft_getcmd_path(char *cmd, char **envar);
void	exiterror(void);
void	execmd(char *argv, char **envar);
int		get_next_line(char **line);

#endif
