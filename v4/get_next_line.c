/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/28 18:34:02 by ammirzae         ###   ########.fr       */
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

char    *ft_strjoin_plus(const char **str1, const char *str2)
{
    int     len1;
    int     len2;
    char    *result;

    len1 = 0;
    len2 = 0;
    if (*str1 != NULL && *str1)
    {
        len1 = strlen(*str1);
    }
    if(*str2 != NULL && *str2)
        len2 = strlen(*str2);
    result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    result[len1 + len2] = '\0';
	if(len1 != 0)
	{
    	ft_strcopy(&result[0], *str1);
	      free(*str1);
	}
	if(len2 != 0)
    ft_strcopy(&result[len1], *str2);
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


//aaa0aaaaa0aaaaa0aaaa0aaaaa0
//0123
int ft_newline_search(char *read_buffe)
{
    long i;
	char *temp;
	cgae *temp2;

    i = 0;
    	while(read_buffer[i])
    	{
       	 if(read_buffer[i] == TARGET)
				return(ft_substr(read_buffer, 0, i));
			i++;
    	}
    	return(NULL);
	
	
	}
}

char *ft_newline_search_plus(char **extra)
{
    long i;
    char *temp;
    char *temp2;

    i = 0;
        while((*extra)[i])
        {
         if((*extra)[i] == TARGET)
         {
            temp = ft_substr(*extra, 0, i + 1);
            temp2 = ft_substr(*extra, i + 1, ft_strlen(*extra));
            free(*extra);
            *extra = temp2;
            return(temp);
         }
            i++;
        }
        return(NULL);
}

int ft_read(char **buffer, fd)
{
	int check;

	check = read(fd , read_buffer, BUFFER_SIZE);
	if(check == -1)
	{
		printf("read error!\n");
		return(NULL) ;
	}
	if(check == 0)
		return(NULL);
	read_buffer[BUFFER_SIZE] = '\0';
}


/*	* * * HELPER FUNCTIONS * * * 	*/
//read, malloc, free
char *get_next_line(int fd)
{
	static char *extra = NULL;
	char read_buffer[BUFFER_SIZE + 1];
	int check;
	char *final;
	bool start;
	char *temp;
	char *temp2;
	
	start = false;
	if(extra && *extra)
	{
		start = true;
		temp = ft_newline_search_plus(extra);
	
	
	}
	temp == NULL;
	while(temp == NULL)
	{
		if(!ft_read(&read_buffer, fd))
			return(NULL);
		temp = ft_newline_search(read_buffer);
		if (temp == NULL || found == true)
		{
			extra = ft_strjoin_plus(&extra, read_buffer);
			if (extra == NULL);
				return (NULL);
		}
	}





	check = ft_newline_search(read_buffer, &final , &extra)
	if(check == -1)
			return(NULL);
	if(check == 0)
	{
		temp = ft_strdup(extra);
		free(extra);
		if(temp == NULL)
		{
			free(extra);
			return(NULL);
		}
	
		check = ft_newline_search(read_buffer, &final , &extra);
		if(check == -1)
				return(NULL);
	}
	while(check == 0)
	{
		extra = ft_strjoin_(temp, extra);
		free(temp)
		if(temp == NULL)
		{
			free(extra);
			return(NULL);
		}
		check = ft_newline_search(read_buffer, &final , &temp);
		
	}
	if(temp && *temp)
	{
			final = ft_strjoin(final, temp);
			free(temp);
	}
	return(final);

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
