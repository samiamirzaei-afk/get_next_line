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
/*
int	call_again(void)
{
	static int line;

	line = 0;
	printf("Line: %d:", line);
	++line;	
	return(line);
}

t_str_nodes	list_new(char *new_str)
{
	t_str_nodes list;

	list = malloc (sizeof(t_str_nodes));
	if(list == NULL)
			return(NULL);


}
*/

//read, malloc, free
void get_next_line(int fd)
{
	int count;
	char buffer[BUFFER_SIZE];
	int read_check;
	
	count = 0;
	while ((read_check = read(fd , buffer, BUFFER_SIZE)) != -1 && count < 30)
	{
			if(read_check == -1)
			{
				printf("read error!\n");
				return ;
			}
			if(read_check == 0)
				return ;

			printf("count: %d, '%s'\n", count++, buffer);
	}
	
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


}
