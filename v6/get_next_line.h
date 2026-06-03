/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:06 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/03 10:20:01 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef TARGET
#  define TARGET '\n'
# endif
# ifndef EMPTY
#  define EMPTY 1
# endif
# ifndef FOUND
#  define FOUND 1
# endif

size_t		ft_strlen(const char *str);
char		*ft_strdup(char *src);
int			ft_putnbr(int nb);
char		*ft_substr(char *str, unsigned int start, size_t len);
int			ft_read(char *buffer, int fd);

typedef struct s_variables
{
	char	*ptr_read_buffer;
	int		check;
	int		extra_check;
	int		read_check;
	char	*result;

}			t_ver;

#endif
