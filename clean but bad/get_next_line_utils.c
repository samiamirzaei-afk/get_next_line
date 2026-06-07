/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:12:26 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/06 12:05:36 by ammirzae         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;
	int		i;

	i = 0;
	length = ft_strlen(src);
	copy = malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	copy[length] = '\0';
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
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

int	ft_read(char *buffer, int fd, char **extra)
{
	int	check;
	int	i;

	i = 0;
	check = read(fd, buffer, BUFFER_SIZE);
	printf("check: %i\n", check);
	if (check == -1)
	{
		if (*extra != NULL){
			printf("**extra: %p | *extra: %p\n", extra, *extra);
			free(*extra);
			*extra = NULL;
			//printf("**extra: %p | *extra: %p\n", extra, *extra);
		}
		return (-1);
	}
	if (check == 0)
	{
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
	}
	buffer[check] = '\0';
	return (check);
}
