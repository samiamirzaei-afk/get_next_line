/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)num)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)num == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	ft_strcopy(char *result, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
}

char	*ft_strjoin_plus(char **str1, char **str2, int tofree)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	if (*str1 != NULL && *str1)
		len1 = ft_strlen(*str1);
	if (*str2 != NULL && *str2)
		len2 = ft_strlen(*str2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
	{
		if (tofree)
			free(*str1);
		return (*str1 = NULL, NULL);
	}
	result[len1 + len2] = '\0';
	if (len1 != 0)
		ft_strcopy(&result[0], *str1);
	if (tofree == 1 && *str1)
		free(*str1);
	if (len2 != 0)
		ft_strcopy(&result[len1], *str2);
	return (*str1 = NULL, result);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (i <= start || len == 0)
		return (ft_strdup(""));
	if (len > (i - start))
		len = i - start;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (str[start] && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	return (result);
}
