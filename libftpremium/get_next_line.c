/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:17:40 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/03 14:17:40 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function_01
char	*ft_read(int fd, char *store)
{
	char	*temp;
	int		readby;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	readby = 1;
	while (!ft_strchr_mod(store, '\n') && readby != 0)
	{
		readby = read(fd, temp, BUFFER_SIZE);
		if (readby < 0)
		{
			free(store);
			free(temp);
			return (NULL);
		}
		temp[readby] = '\0';
		store = ft_strjoin_mod(store, temp);
	}
	free (temp);
	return (store);
}

//function_02
char	*ft_currline(char *store)
{
	int		cnt;
	char	*line;

	cnt = 0;
	if (!store[cnt])
		return (NULL);
	while (store[cnt] && store[cnt] != '\n')
		cnt++;
	line = ft_substr_mod(store, 0, cnt + (store[cnt] == '\n'));
	return (line);
}

//function_03
char	*ft_trimline(char *store)
{
	char	*str;
	int		cnt0;
	int		cnt1;

	cnt0 = 0;
	cnt1 = 0;
	while (store[cnt0] && store[cnt0] != '\n')
		cnt0++;
	if (!store[cnt0])
	{
		free(store);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(store) - cnt0 + 1));
	if (!str)
		return (NULL);
	cnt0++;
	while (store[cnt0])
		str[cnt1++] = store[cnt0++];
	str[cnt1] = '\0';
	free (store);
	return (str);
}

//function_00
char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = ft_read(fd, store);
	if (!store)
		return (0);
	line = ft_currline(store);
	store = ft_trimline(store);
	return (line);
}
