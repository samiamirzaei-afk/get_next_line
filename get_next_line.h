/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:06 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/08 15:04:53 by ammirzae         ###   ########.fr       */
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

typedef struct s_variables
{
	char	*ptr_read_buffer;
	int		check;
	int		bytes;
	char	*result;

}			t_ver;

/*get_next_line.c*/
void		ft_strcopy(char *result, char *str);
char		*ft_strjoin_plus(char **str1, char **str2, int tofree);
int			ft_newline_search(char **extra, char **result);
char		*ft_get_line(char **extra, char *read_buffer, int fd, t_ver *var);
char		*get_next_line(int fd);

size_t		ft_strlen(const char *str);
char		*ft_strdup(char *src);
char		*ft_substr(char *str, unsigned int start, size_t len);
int			ft_read(int fd, char **extra, char **buff);

#endif
