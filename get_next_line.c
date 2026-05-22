/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/21 11:33:30 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	call_again(void)
{
	static unsigned int line;

	printf("Line[%d]:", line);
	++line;	
	return(line);
	
	
}

/*	* * * TEST FUNCTIONS * * * 	*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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


t_str_list	*list_new(char *new_str)
{
	t_str_list *list;

	list = malloc(sizeof(t_str_list));
	if(list == NULL)
			return(NULL);
	list->content = new_str;
	list->next = NULL;
	return(list);
}



void	ft_show(t_str_list *ptr)
{
//	t_str_list *current;

//	current = *ptr;
	while(ptr != NULL)
	{	
		call_again();
		printf("%s\n", ptr->content);
		ptr = ptr->next;
	}


}


/*	* * * HELPER FUNCTIONS * * * 	*/





//read, malloc, free
void get_next_line(int fd)
{
	t_str_list *buffer_list;
	t_str_list	*ptr;
	int count;
	char buffer[BUFFER_SIZE];
	int check;

	buffer_list = malloc(sizeof(t_str_list));	
	ptr = buffer_list;
	count = 0;
	while (count < 10)
	{
			check = read(fd , buffer, BUFFER_SIZE);
			if(check == -1)
			{
				printf("read error!\n");
				return ;
			}
			if(check == 0)
				break;
		
	buffer_list->next = list_new(ft_strdup(buffer));
	}
	
	ft_show(ptr);


	return;

}

int main(int argc, char **argv) 
{
	int i;
	size_t count;
	int fd;

	
	
	
	
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
