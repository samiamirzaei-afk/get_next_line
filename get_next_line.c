/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/12 13:46:25 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*tofree: 0 free non, 1= frees str1*/
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

/*	* * * TEST FUNCTIONS * * * 	*/
int	ft_newline_search(char **extra, char **result)
{
	long	i;
	char	*temp2;

	i = 0;
	while (*extra && (*extra)[i])
	{
		if ((*extra)[i] == TARGET)
		{
			*result = ft_substr(*extra, 0, i + 1);
			if (*result == NULL)
				return (free(*extra), *extra = NULL, 1);
			temp2 = ft_substr(*extra, i + 1, ft_strlen(*extra));
			if (temp2 == NULL)
			{
				free(*result);
				*result = NULL;
				return (free(*extra), *extra = NULL, 1);
			}
			free(*extra);
			*extra = temp2;
			return (1);
		}
		i++;
	}
	return (0);
}

/*	* * * HELPER FUNCTIONS * * * 	*/

char	*get_next_line(int fd)
{
	static char	*extra = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	t_ver		var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(extra), extra = NULL, NULL);
	var.ptr_read_buffer = read_buffer;
	while (1)
	{
		if (ft_newline_search(&extra, &var.result))
			return (var.result);
		var.bytes = ft_read(fd, &extra, &var.ptr_read_buffer);
		if (var.bytes <= 0)
			return (NULL);
		extra = ft_strjoin_plus(&extra, &var.ptr_read_buffer, 1);
		if (extra == NULL)
			return (NULL);
	}
	return (NULL);
}

/*
char	*ft_get_line(char **extra, char *read_buffer, int fd, t_ver *var)
{
	while (1)
	{
		var->read_check = ft_read(read_buffer, fd, extra,
				&var->ptr_read_buffer);
		if (var->read_check == -1)
			return (NULL);
		if (var->read_check == 0)
			return (NULL);
		if (var->read_check < BUFFER_SIZE)
		{
			var->result = ft_strdup(*extra);
			return (free(*extra), *extra = NULL, var->result);
		}
		*extra = ft_strjoin_plus(extra, &var->ptr_read_buffer, 1);
		if (*extra == NULL)
			return (NULL);
		var->check = ft_newline_search(extra, &var->result);
		if (var->check == -1)
			return (NULL);
		if (var->check == FOUND)
			return (var->result);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*extra = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	t_ver		var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(extra), extra = NULL, NULL);
	var.extra_check = EMPTY;
	if (extra && extra[0])
	{
		var.extra_check = ft_newline_search(&extra, &var.result);
		if (var.extra_check == -1)
			return (NULL);
		if (var.extra_check == FOUND)
			return (var.result);
	}
	var.ptr_read_buffer = read_buffer;
	return (ft_get_line(&extra, read_buffer, fd, &var));
}
*/
/*
char	*get_next_line(int fd)
{
	static char	*extra = NULL;
	char		read_buffer[BUFFER_SIZE + 1];
	char		*result;
	t_ver		var;

	var.extra_check = EMPTY;
	if(extra && extra[0])
	{
		var.extra_check = ft_newline_search(&extra, &result);
		if (var.extra_check == -1)
			return (NULL);
		if (var.extra_check == FOUND)
			return (result);
	}
	while(1)
	{
		var.read_check = ft_read(read_buffer, fd);
		if(var.read_check == -1 || var.read_check == 0)
		{
			if(extra)
				return(free(extra), NULL);
			return (NULL);
		}
		var.ptr_read_buffer = read_buffer;
		extra = ft_strjoin_plus(&extra, &var.ptr_read_buffer, 1);
		if(extra == NULL)
			return(NULL);
		var.check = ft_newline_search(&extra, &result);
		if (var.check == -1)
			return(NULL);
		if (var.check == FOUND)
			return (result);
	}
	return(NULL);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;
	int		k;

	if (argc < 2)
	{
		printf("No file error\n");
		return (1);
	}
	k = 1;
	while (argv[k] != NULL)
	{
		fd = open(argv[k], O_RDONLY);
		//	printf("fd:%d\n\n",fd);
		i = 0;
		while (1)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			printf("%s", line);
			free(line);
			i++;
		}
		close(fd);
		get_next_line(-2);
		k++;
	}
}
*/
