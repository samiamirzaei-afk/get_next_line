/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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

int	read_until_newline(int fd, char **extra)
{
	char	*ptr_buffer;
	char	buffer[BUFFER_SIZE + 1];
	int	bytes;

	while (1)
	{
		if (*extra && ft_strchr(*extra, TARGET))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(*extra), *extra = NULL, 0);
		ptr_buffer = buffer;
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		*extra = ft_strjoin_plus(extra, &ptr_buffer, 1);
	}
	return (FOUND);
}

char	*cut_newline(char *extra)
{
	size_t	len;

	if (extra == NULL)
		return (NULL);
	len = 0;
	while (extra[len] && extra[len] != TARGET)
		len++;
	if (extra[len] == TARGET)
		len++;
	return (ft_substr(extra, 0, len));
}

int	extra_after_cut(char **extra, size_t result_len)
{
	char	*temp;
	size_t	extra_len;

	extra_len = ft_strlen(*extra);
	if (result_len == extra_len)
		return (free(*extra), *extra = NULL, FOUND);
	temp = ft_substr(*extra, result_len, extra_len - result_len);
	if(temp == NULL)
		return(free(*extra), *extra = NULL, 0);
	free(*extra);
	*extra = temp;
	return (FOUND);
}

char	*get_next_line(int fd)
{
	static char	*extra = NULL;
	char		*result;
	size_t		result_len;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(extra), extra = NULL, NULL);
	if(!(read_until_newline(fd, &extra)))
		return (NULL);
	result = cut_newline(extra);
	if (!result)
		return (free(extra), extra = NULL, NULL);
	result_len = ft_strlen(result);
	if(!(extra_after_cut(&extra, result_len)))
		return (free(result), NULL);
	return(result);
}

/*
int main(int argc, char **argv) 
{
	int i;
	int fd;
	char *line;

	if (argc < 2)
	{
		printf("No file error\n");
		return (1);
	}	
	
	
	i = 0;
	fd = open(argv[1], O_RDONLY);

	while(1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break;
		}
		printf("%s", line);
		i++;
		free(line);
	}
	close(fd);
	get_next_line(-2);
}
*/
