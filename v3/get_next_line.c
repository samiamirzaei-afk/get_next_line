/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/28 11:01:16 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




static void	ft_strcopy(char *result, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len1 + len2] = '\0';
	ft_strcopy(&result[0], str1);
	ft_strcopy(&result[len1], str2);
	return (result);
}


/*	* * * TEST FUNCTIONS * * * 	*/

char    *ft_cat_str(char *read_buffer, long length)
{
    char *str;
    long i;

	i = 0;
    if (length == -1)
	{
		while(read_buffer[i])
				i++;
		length = i;
	}
    str = malloc(length + 2);
    if (str == NULL)
    {
        printf("MALLOC FAIL at ft_cat_str\n");
        return (NULL);
    }
    str[length + 1] = '\0';
	i = 0;
	while(i <= length)
	{
		str[i] = read_buffer[i];
		i++;
	}
    return (str);
}

char *ft_newline_search(char *read_buffer, char **extra, bool *found)
{
    long i;
    char *str;

    i = 0;
    while(read_buffer[i])
    {
        if(read_buffer[i] == '\n')
        {
            str = ft_cat_str(&read_buffer[0], i);
            if(str == NULL)
            {
                    printf("MALLOC FAIL at ft_newline_search (ft_cat_str)\n");
                    return(NULL);
            }
			*extra = ft_cat_str(&read_buffer[i + 1], -1);
			if(extra == NULL)
					return(NULL);
			*found = true;
			return(str);
        }
		i++;
    }
	*extra = ft_strdup(read_buffer);
    return(ft_strdup(""));
}

/*	* * * HELPER FUNCTIONS * * * 	*/


//read, malloc, free
char *get_next_line(int fd)
{
	static char *left_over = NULL;
	char read_buffer[BUFFER_SIZE + 1];
	int check;
	char *final;
	bool found;
	char *temp;

	found = false;
	if(left_over && *left_over)
	{
		temp = ft_newline_search(left_over, &left_over, &found);
		if(found == true)
			return(temp);
	}
	while(found == false)
	{
		check = read(fd , read_buffer, BUFFER_SIZE);
		if(check == -1)
		{
			printf("read error!\n");
			return(NULL) ;
		}
		if(check == 0)
			return(NULL);
			
		read_buffer[BUFFER_SIZE] = '\0';
		final = ft_newline_search(read_buffer, &left_over, &found);
		if(final == NULL)
			return(NULL);
		if(temp && *temp)
		{
			final = ft_strjoin(final, temp);
			free(temp);
		}

		return(final);
	}
}

int main(int argc, char **argv) 
{
	int i;
	int fd;

	if (argc < 2)
	{
		printf("No file error\n");
		return (1);
	}	
	
	
	
	i = 1;
	i++;
	fd = open(argv[1], O_RDONLY);

	while(1){
			char *line = get_next_line(fd);
			if (!line){
					break;
			}
			printf("%s", line);

	}
}
