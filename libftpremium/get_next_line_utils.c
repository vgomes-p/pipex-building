/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <vgomes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:17:30 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/12/03 14:17:30 by vgomes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function_00
size_t	ft_strlen(const char *var)
{
	size_t	cnt;

	cnt = 0;
	while (var[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

//function_01
char	*ft_strchr_mod(char const *str, int ch)
{
	int		cnt;
	char	*strbase;

	if (!str || !ch)
		return (NULL);
	cnt = 0;
	strbase = (char *)str;
	while (strbase[cnt])
	{
		if (strbase[cnt] == (char) ch)
			return (&strbase[cnt]);
		cnt++;
	}
	return (0);
}

//function_02
char	*ft_strjoin_mod(char *str0, char *str1)
{
	char		*nwstr;
	size_t		cnt0;
	size_t		cnt1;

	if (!str0)
	{
		str0 = malloc(sizeof(char));
		str0[0] = '\0';
	}
	nwstr = malloc((ft_strlen(str0) + ft_strlen(str1)) + 1);
	if (!nwstr)
		return (NULL);
	cnt0 = 0;
	cnt1 = 0;
	while (str0[cnt0])
	{
		nwstr[cnt0] = str0[cnt0];
		cnt0++;
	}
	while (str1[cnt1])
		nwstr[cnt0++] = str1[cnt1++];
	nwstr[cnt0] = '\0';
	free(str0);
	return (nwstr);
}

//function_03
char	*ft_substr_mod(char const *str, unsigned int start, size_t len)
{
	char	*nwstr;
	size_t	cnt0;
	size_t	cnt1;

	nwstr = malloc(len + 1);
	if (!nwstr)
		return (NULL);
	if (!str)
		return (NULL);
	cnt0 = start;
	cnt1 = 0;
	while (cnt0 < ft_strlen(str) && cnt1 < len)
		nwstr[cnt1++] = str[cnt0++];
	nwstr[cnt1] = '\0';
	return (nwstr);
}
