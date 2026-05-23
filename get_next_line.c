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

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	i = 0;
//	while (str[i] != '\0')
//	{
		write(1, &str[0], 1);
		write(1, &str[1], 1);
		write(1, &str[2], 1);
		write(1, &str[3], 1);
		write(1, &str[4], 1);
		write(1, &str[5], 1);
		write(1, &str[6], 1);
		write(1, &str[7], 1);
		write(1, &str[8], 1);
		write(1, &str[9], 1);
		write(1, &str[10], 1);
		write(1, &str[11], 1);


//	}
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

//	printf("%s\n", copy);
	return (copy);
}


t_list	*list_new(char *new_str)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if(list == NULL)
			return(NULL);
	list->content = new_str;
	list->next = NULL;
	return(list);
}



void	ft_show(t_list *ptr)
{
//	t_list *current;

//	current = *ptr;
	while(ptr != NULL)
	{	
		call_again();
		write(1, &ptr->content[0], ft_strlen2(ptr->content));

		//printf("%s\n", ptr->content);
		ptr = ptr->next;
	}


}


/*	* * * HELPER FUNCTIONS * * * 	*/





//read, malloc, free
void get_next_line(int fd)
{
	t_list *buffer_list;
	t_list	*ptr;
	int count;
	char buffer[BUFFER_SIZE];
	int check;

	buffer_list = malloc(sizeof(t_list));	
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
	buffer_list = buffer_list->next;
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
