/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/01 10:23:27 by ammirzae         ###   ########.fr       */
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
	{
		if(*str1)
			free(*str1);
	}
	if(len2 != 0)
		ft_strcopy(&result[len1], *str2);
//	if(tofree == 2 || tofree == 3)
//		free(*str2);
    return (result);
}



/*	* * * TEST FUNCTIONS * * * 	*/

int ft_newline_search(char **extra, char **result)
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
		    	return (free(*extra),-1);
	    	temp2 = ft_substr(*extra, i + 1, ft_strlen(*extra));
            	if (temp2 == NULL)
		{
			free(*extra);
			free(*result);
		    return (-1);
		}
	    free(*extra);
	    *extra = temp2;
            return(1);
         }
            i++;
    }
    return(0);
}
//tofree: 0 = non, 1= free extra
/*
int ft_newline_search_plus(char **extra, char **result, int tofree, char **stored_buffer)
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
	    	*stored_buffer = temp2;
		return(1);
	    }
	    *extra = temp2;
            return(1);
         }
            i++;
        }
        return(0);
}
*/
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
	
	read_check = 1;	
	extra_check = EMPTY;	
	if(extra && extra[0])
	{
		extra_check = ft_newline_search(&extra, &result);
		if (extra_check == -1)
			return (NULL);
		if (extra_check == FOUND)
			return (result);
	}
	while(read_check)
	{
		read_check = ft_read(read_buffer, fd);
		if(read_check == -1 || read_check == 0)
		{	
			if(extra)
				return(free(extra), NULL);
			return (NULL);
		}
		//check: 0 = not found
		//	 1= found FOUND
		//	 -1 = malloc fail
		ptr_read_buffer = read_buffer;
		extra = ft_strjoin_plus(&extra, &ptr_read_buffer, 1);
		if(extra == NULL)
			return(NULL);	
		check = ft_newline_search(&extra, &result);
		if (check == -1)
			return(NULL);
	//	extra_check: 0= extra has stuff, but without target / FULL
	//		     1= extra is empty /EMPTY
		if (check == FOUND)
			return (result);
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
