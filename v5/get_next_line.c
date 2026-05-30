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




static void	ft_strcopy(char *result, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
}

//tofree: 0 free non, 1= frees str1, 2= str2, 3=  free both
char    *ft_strjoin_plus(char **str1, char **str2, int tofree)
{
    int     len1;
    int     len2;
    char    *result;

    len1 = 0;
    len2 = 0;
    if (*str1 != NULL && *str1)
        len1 = ft_strlen(*str1);
    if(*str2 != NULL && *str2)
        len2 = ft_strlen(*str2);
    result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    result[len1 + len2] = '\0';
	if(len1 != 0)
    		ft_strcopy(&result[0], *str1);
	if(tofree == 1 || tofree == 3)
		free(*str1);
	if(len2 != 0)
		ft_strcopy(&result[len1], *str2);
	if(tofree == 2 || tofree == 3)
		free(*str2);
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
    str = malloc(length  + 1);
    if (str == NULL)
    {
        printf("MALLOC FAIL at ft_cat_str\n");
        return (NULL);
    }
    str[length] = '\0';
	i = 0;
	while(i < length)
	{
		str[i] = read_buffer[i];
		i++;
	}
    return (str);
}
//tofree: 0 = non, 1= free extra
int ft_newline_search_plus(char **extra, char **result, int tofree, char **temp3)
{
    long i;
    char *temp2;

    i = 0;
        while((*extra)[i])
        {
         if((*extra)[i] == TARGET)
         {
            *result = ft_substr(*extra, 0, i + 1);
            if (*result == NULL)
		    return (-1);
	    temp2 = ft_substr(*extra, i + 1, ft_strlen(*extra));
            if(tofree == 1)
		    free(*extra);
            if (temp2 == NULL)
		    return (-1);
	    if(tofree == 0)
	    {
	    	*temp3 = temp2;
		return(1);
	    }
	    *extra = temp2;
            return(1);
         }
            i++;
        }
        return(0);
}

int ft_read(char *buffer, int fd)
{
	int check;

	check = read(fd , buffer, BUFFER_SIZE);
	if(check == -1)
	{
		printf("read error!\n");
		return(-1) ;
	}
	if(check == 0)
		return(0);
	buffer[check] = '\0';
	return (check);
}


/*	* * * HELPER FUNCTIONS * * * 	*/
//read, malloc, free
char *get_next_line(int fd)
{
	static char *extra = NULL;
	char read_buffer[BUFFER_SIZE + 1];
	char *ptr_read_buffer;
	int check;
	int extra_check;
	int read_check;
	char *result;
	char *stored_buffer;
/*
	if(fd <= -2)
	{
		free(extra);
		return(NULL);
	}
*/
	read_check = 1;	
	extra_check = 1;	
	if(extra && *extra)
	{
		 extra_check = ft_newline_search_plus(&extra, &result, 1, &stored_buffer);
		if (extra_check == -1)
			return (NULL);
		if (extra_check == 1)
			return (result);
	}

	while(read_check)
	{
		read_check = ft_read(read_buffer, fd);
		if(read_check == -1)
			return (NULL);
		if(read_check == 0)
		{
			if((extra && *extra) || extra != NULL)
			{
				stored_buffer = extra;
				extra = NULL;
				return(stored_buffer);

			}
			if(extra_check == 0)
				return(extra);
			break;
		}
		ptr_read_buffer = read_buffer;
		//check: 0 = not found, 1= found, -1= malloc fail
		check = ft_newline_search_plus(&ptr_read_buffer, &result, 0, &stored_buffer);
		if (check == -1)
			return(NULL);
	//	extra_check: 0= extra has stuff, but without target
	//		     1= extra is empty
		if (check == 1 && extra_check == 1)
		{
//			result = ft_strjoin_plus(&extra, &result, 2);
//			extra = ft_strjoin_plus(&extra, &stored_buffer, 2);	
			extra = ft_strdup(stored_buffer);
			free(stored_buffer);
			return (result);

		}
		if (check == 1 && extra_check == 0)
		{
			result = ft_strjoin_plus(&extra, &result, 3);	
			extra = stored_buffer;
			return (result);
		}
		if (check == 0 && extra_check == 1)
		{
			extra = ft_strjoin_plus(&extra, &ptr_read_buffer, 0);
				if (extra == NULL)
					return (NULL);
			extra_check = 1;	
		}
		if (check == 0 && extra_check == 0)
		{
			extra = ft_strjoin_plus(&extra, &ptr_read_buffer, 1);
				if (extra == NULL)
					return (NULL);
		}
	}
	return(NULL);

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
