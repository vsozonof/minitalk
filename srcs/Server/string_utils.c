/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:32:14 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/24 09:03:34 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!(s1) && !(s2))
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (len == 0)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (!(str))
		return (NULL);
	len = -1;
	while (++len < ft_strlen(s1))
		str[len] = s1[len];
	i = 0;
	while (len < (ft_strlen(s2) + ft_strlen(s1)))
	{
		str[len] = s2[i];
		len++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_charjoin(char *str, char c, int len)
{
	static int	flag;
	static int	index;

	if (flag == 0)
	{
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		flag = 1;
	}
	if (index < len)
		str[index] = c;
	else if (index == len)
	{
		str[index] = '\0';
		flag = 0;
		index = 0;
		return (str);
	}
	index++;
	return (str);
}
