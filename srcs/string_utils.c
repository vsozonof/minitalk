/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:32:14 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/20 10:44:36 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_char_to_str(char c)
{
	char	*letter;

	if (c == '\0')
		return (NULL);
	letter = malloc(sizeof(char) * 2);
	if (!letter)
		return (NULL);
	letter[0] = c;
	letter[1] = '\0';
	return (letter);
}

char	*ft_charjoin(char *str, char c)
{
	char	*msg;
	char	*new_char;

	new_char = ft_char_to_str(c);
	msg = ft_strjoin(str, new_char);
	free(new_char);
	free(str);
	return (msg);
}
