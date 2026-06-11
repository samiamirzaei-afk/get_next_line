/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
#include <fcntl.h>
#include <stdio.h>
*/

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# ifndef LAST_LINE
#  define LAST_LINE -1
# endif
# ifndef FOUND
#  define FOUND 1
# endif

# ifndef TARGET
#  define TARGET '\n'
# endif

/* get_next_line.c */
char    *ft_strdup(char *src);
int	read_until_newline(int fd, char **extra);
char	*cut_newline(char *extra);
int	extra_after_cut(char **extra, size_t result_len);
char	*get_next_line(int fd);

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int num);
void	ft_strcopy(char *result, char *str);
char	*ft_strjoin_plus(char **str1, char **str2, int tofree);
char	*ft_substr(char *str, unsigned int start, size_t len);


#endif
