/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:07 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/11/07 12:57:07 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>

/* FROM LIBFT */
void	ft_bzero(void *str, size_t nby);
void	*ft_calloc(size_t num_el, size_t numby);
void	*ft_memset(void *buffer, int value, size_t len);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *str, char ch);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str0);
char	*ft_strjoin(char const *str0, char const *str1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *var);
int		ft_strncmp(const char *str0, const char *str1, size_t numby);
char	*ft_strnstr(const char *big, const char *ltl, size_t lench);

#endif
