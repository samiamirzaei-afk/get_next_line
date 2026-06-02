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
#include <stdio.h>

static char	*read_until_newline(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	if (stash && ft_strchr(stash, '\n'))
		return (stash);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
		if (!stash || ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line_from_stash(char *stash)
{
	size_t	len;
	char	*line;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	return (line);
}

static char	*update_stash_after_extract(char *stash, size_t line_len)
{
	char	*new_stash;
	size_t	stash_len;

	stash_len = ft_strlen(stash);
	if (line_len == stash_len)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, line_len, stash_len - line_len);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_until_newline(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line_from_stash(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line_len = ft_strlen(line);
	stash = update_stash_after_extract(stash, line_len);
	return (line);
}

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
}
