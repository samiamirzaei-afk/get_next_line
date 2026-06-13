/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:01:06 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/13 15:14:20 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef TARGET
#  define TARGET '\n'
# endif

/* Utils */
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int num);
void	ft_strcopy(char *dest, char *src);
char	*ft_strjoin_plus(char **str1, char **str2, short tofree);
char	*ft_strdup(char *src);

/* get_next_line */
char	*ft_substr(char *str, int start, int len);
int		read_until_newline(char **extra, char **buffer, int fd);
char	*ft_cut_newline(char *extra);
int		ft_extra_after_cut(char **extra, char *result);
char	*get_next_line(int fd);
#endif
