/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/25 16:09:40 by ammirzae         ###   ########.fr       */
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
 
char	*ft_cat_str(char *read_buffer, size_t length)
{
	char *str;
	size_t i;

	i = 0;
	str = malloc((length + 1) * sizeof(char));
	if(str == NULL)
	{
		printf("MALLOC FAIL at ft_cat_str\n")
			return(NULL);

	}
	str[length] = '\0';
	while(i < length)
		str[i] = read_buffer[i];
	return(str);
}

// if no new line found, save it all.
// 				++CASE 1++
//	link01	"José Manuel Velásquez Castillo"
//	link02	"(born 4 June 1952 in Lima) is a\n"
//	PRINT HERE, 
//
// 				++CASE 2++
//	link01 "Peruvian former footballer who played"
//	link02 "as a midfielder.\n" 
//	Link03 "Nicknamed "El Patrón"
//
int	ft_newline_search(char *buffer, t_list head)
{
	size_t i;
	size_t k;
	char *str;
	int found;

	found = 0;
	i = 0;
	k = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
		{
			str = ft_cat_str(&buffer[k], (i - k))	
			if(str == NULL)
			{
					printf("MALLOC FAIL at ft_newline_search (ft_cat_str)\n");
					return(NULL);
			}
			head->content = str;
			head->next = list_new();
			if(head == NULL)
			{
					printf("MALLOC FAIL at ft_newline_search (list_new)\n");
					return(NULL);
			}
				k = i;
				found = 1;
		}
		i++;
	}
	if(found == 1)
			return (1);

	return (-1);
}

/*	* * * HELPER FUNCTIONS * * * 	*/

char	*ft_cat_str(t_list *buffer, size_t length)
{
	char *str;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	str = malloc((length + 1) * sizeof(char));
	str[length] = '\0';
	while(buffer->content)
	{
			j = 0;
			while(buffer->content[j])
			{
				str[i] = buffer->content[j];
				i++;
				j++;
			}
			buffer = buffer->next;
	}
	return(str);
}



//read, malloc, free
void get_next_line(int fd)
{
	t_list *list_buffer;
	t_list	*ptr;

	char read_buffer[BUFFER_SIZE + 1];
	int check;
	size_t length;

	length = 0;
	if(list_buffer == NULL)
		return ;
	ptr = buffer_list;
	while(1)
	{
			check = read(fd , read_buffer, BUFFER_SIZE);
			if(check == -1)
			{
				printf("read error!\n");
				return ;
			}
			if(check == 0)
				break;
	read_buffer[BUFFER_SIZE] = '\0';
	if (ft_newline_search(read_buffer, list_buffer) == -1)
	{
		ptr->content = ft_strdup(read_buffer);
		ptr->next = list_new();
		ptr = ptr->next;
			if(ptr == NULL)
			{
					printf("MALLOC FAIL at get_next_line (list_new)\n");
					return(NULL);
			}
	
	}
	
		if(ft_newline_search(buffer))
		{
			call_again();
			printf("%s", ft_cat_str(buffer_list, ((length * BUFFER_SIZE) + check)));
			length = 0;
			ft_lstclear(&buffer_list, free);
			buffer_list = list_new();
			ptr = buffer_list;
		}
	}	
	printf("\n\n");


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
	i++;
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
