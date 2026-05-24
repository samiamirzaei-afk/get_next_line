/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:06 by ammirzae          #+#    #+#             */
/*   Updated: 2026/05/23 12:35:24 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 7
#endif


size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
int	ft_putnbr(int nb);


typedef struct s_list
{
	char		*content;
	struct s_list	*next;

}	t_list;

void	ft_lstclear(t_list **head, void (*del)(void *));
