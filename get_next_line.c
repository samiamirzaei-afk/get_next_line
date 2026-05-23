/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/23 14:07:59 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	call_again(void)
{
	static unsigned int line;

	write(1, "Line", 4);
	ft_putnbr(line);
	write(1, " :", 2);
	++line;	
	return(line);
	
	
}

/*	* * * TEST FUNCTIONS * * * 	*/


t_list	*list_new(void)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if(list == NULL)
			return(NULL);
	list->content = NULL;
	list->next = NULL;
	return(list);
}

void	ft_show(t_list *ptr)
{
	while(ptr->next != NULL)
	{	
		call_again();
		if(ptr->content)
			write(1, &ptr->content[0], ft_strlen(ptr->content));
		ptr = ptr->next;
	}
}


int	ft_newline_check(char *buffer)
{
	size_t i;

	i = 0;
	while(buffer[i] && buffer[i] != '\n')
	{
		
	
	
	}


}


/*	* * * HELPER FUNCTIONS * * * 	*/





//read, malloc, free
void get_next_line(int fd)
{
	t_list *buffer_list;
	t_list	*ptr;
	char buffer[BUFFER_SIZE + 1];
	int check;

	buffer_list = malloc(sizeof(t_list));	
	ptr = buffer_list;
	while(1)
	{
			check = read(fd , buffer, BUFFER_SIZE);
			if(check == -1)
			{
				printf("read error!\n");
				return ;
			}
			if(check == 0)
				break;
	buffer[BUFFER_SIZE] = '\0';
	check = ft_newline_check(buffer);
	if(check = 1)
	{
			ft_show(buffer_list);
			buffer_list = ptr;
	}
	ptr->content = ft_strdup(buffer);
	ptr->next = list_new();
	ptr = ptr->next;
	}	
	ft_show(buffer_list);


	return;

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
	fd = open(argv[1], O_RDONLY);

	
	get_next_line(fd);
/*	i = 0;
	while(i < 15)
	{
		printf("%d\n", i++);
	}
*/
}

/*
 
	
//	int j = 500;

//	printf("%d\n", (char)&i + 1);
//	return (0);


	 	
	int j = 500;
    
    // Get pointer to j
    unsigned char *byte_ptr = (unsigned char *)&j;
    
    // Access each byte
    printf("Byte at &j (offset 0): %d\n", byte_ptr[0]);   // 244 (0xF4)
    printf("Byte at &j+1 (offset 1): %d\n", byte_ptr[1]); // 1   (0x01)
    printf("Byte at &j+2 (offset 2): %d\n", byte_ptr[2]); // 0
    printf("Byte at &j+3 (offset 3): %d\n", byte_ptr[3]); // 0
    
    // Or specifically just &j+1
    printf("Value at &j+1: %d\n", *(byte_ptr + 1)); // Also 1
    
    return 0;
*/	
