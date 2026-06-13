/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/13 15:10:05 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *ft_substr(char *str, int start, int len)
{
    int     str_len;
    char    *result;
    int i;

    str_len = ft_strlen(str);
    if(start > str_len)
        return(ft_strdup(""));
    if(len > (str_len - start))
            len = str_len - start;
    result = malloc ((len + 1) *  sizeof(char));
    if(result == NULL)
            return(NULL);
    result[len] = '\0';
    i = 0;
    while(i < len)
    {
        result[i] = str[start];
        i++;
        start++;
    }
    return(result);
}

int read_until_newline(char **extra, char **buffer, int fd)
{
	int bytes;
	while(1)
	{
		if(*extra && ft_strchr(*extra, TARGET))
				return(1);

		bytes = read(fd, *buffer, BUFFER_SIZE);
		if(bytes == -1)
				return(free(*extra), *extra = NULL, 0);
		if(bytes == 0)
		{
			if(*extra)
					return(1);
			return(0);
		}
		(*buffer)[bytes] = '\0';
		*extra = ft_strjoin_plus(extra, buffer, 1);
		if(*extra == NULL)
				return(0);
	}
}

char	*ft_cut_newline(char *extra)
{
	int i;
	char *result;

	i = 0;
	while(extra && extra[i] && extra[i] != TARGET)
			i++;
	if(extra[i] == TARGET)
			i++;
	result = ft_substr(extra, 0, i);
	return(result);
}

int	ft_extra_after_cut(char **extra, char *result)
{
	int result_len;
	int extra_len;
	char *temp;
	extra_len = ft_strlen(*extra);
	result_len = ft_strlen(result);
	if(extra_len == result_len)
		return(free(*extra), *extra = NULL, 1);
	temp = ft_substr(*extra, result_len, extra_len);
	if(temp == NULL)
				return(free(*extra), *extra = NULL, 0);
	free(*extra);
	*extra = temp;
	return(1);
}
char *get_next_line(fd)
{
	static char *extra = NULL;
	char	*result;
	char	buffer[BUFFER_SIZE + 1];
	char	*buffer_ptr;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(free(extra), extra = NULL, NULL);
	result = NULL;
	buffer_ptr = buffer;
	if(!(read_until_newline(&extra, &buffer_ptr,  fd)))
		return(0);
	result = ft_cut_newline(extra);
	if(!result)
			return(NULL);
	if(!(ft_extra_after_cut(&extra, result)))
			return(free(result), NULL);
	return(result);
		
}
/*
int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("no file error\n");
		return(0);}

	int fd;
	char *line;
	int i;

	i = 0;
	fd = open (argv[1], O_RDONLY);
	while(2)
	{
		line = get_next_line(fd);
		if(!line)
		{
			break;
		}
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	get_next_line(-3);
//	write(1, "END OF 5 LINES\n", 15);
}
*/

