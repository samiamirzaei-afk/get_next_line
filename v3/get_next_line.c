/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/27 17:18:13 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    return("");
}

/*	* * * HELPER FUNCTIONS * * * 	*/


//read, malloc, free
char *get_next_line(int fd)
{
	static char *extra;
	char read_buffer[BUFFER_SIZE + 1];
	int check;
	char *final;
	bool found;

	found = false;
	if(extra)
	{
		final = ft_newline_search(extra, &extra, &found);
		if(found)
			return(final);
	}
	while(!found )
	{
			check = read(fd , read_buffer, BUFFER_SIZE);
			if(check == -1)
			{
				printf("read error!\n");
				return(NULL) ;
			}
			if(check == 0)
				break;
			
	read_buffer[BUFFER_SIZE] = '\0';
	final = ft_newline_search(read_buffer, &extra, &found);
	if(final == NULL)
			return(NULL) ;
	
	}

/*
	printf("%s", ft_cat_str(buffer_list, ((length * BUFFER_SIZE) + check)));
			length = 0;
			ft_lstclear(&buffer_list, free);
			buffer_list = list_new();
			ptr = buffer_list;
		}
	}
*/

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
