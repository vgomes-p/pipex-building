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
char	*ft_strnstr(const char *big, const char *ltl, size_t lench);
char	*ft_strjoin(char const *str0, char const *str1);
char	**ft_split(char const *str, char ch);
void	ft_putstr_fd(char *str, int fd);


#endif
