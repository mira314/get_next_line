/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 08:15:32 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/03 13:26:07 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (!s[i])
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;
	size_t	len_s1;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1);
	size = len_s1 + ft_strlen(s2);
	result = (char *)malloc(sizeof(char ) * (size + 1));
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[len_s1 + i] = (char)s2[i];
		i++;
	}
	result[len_s1 + i] = 0;
	return (result);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
