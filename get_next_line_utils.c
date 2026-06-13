/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:06:29 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/13 15:02:03 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
			i++;
	return(i);
}


char *ft_strchr(char *str, int num)
{
	int i;

	if(!str)
		return(NULL);
	i = 0;
	while(str[i])
	{
			if(str[i] == num)
					return(&str[i]);
			i++;
	}
	if(str[i] == '\0' && str[i] == num)
			return(&str[i]);
	return(NULL);

}

void	ft_strcopy(char *dest, char *src)
{
	int i;
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char *ft_strjoin_plus(char **str1, char **str2, short tofree)
{
	int len1;
	int len2;
	char *result;

	len1 = 0;
	len2 = 0;
	if(*str1)
		len1 = ft_strlen(*str1);
	if(*str2)
		len2 = ft_strlen(*str2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if(!result)
			return(free(*str1), *str1 = NULL, NULL);
	if(len1 != 0)
			ft_strcopy(&result[0], *str1);
	if(*str1 && tofree == 1)
			free(*str1);
	if(len2 != 0)
			ft_strcopy(&result[len1], *str2);
	result[len1 + len2] = '\0';
	return(result);
}

char    *ft_strdup(char *src)
{
    int        length;
    char    *copy;
    int        i;

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


/*
int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf("no need 2 str\n");
        return(0);
    }

	char *null;
	char *result;
	null = NULL;
//	result = ft_strjoin_plus(&argv[1], &argv[2], 0)
//	result = ft_strjoin_plus(&argv[1], &null, 0);
//	result = ft_strjoin_plus(&null, &argv[2], 0);
    printf("%s", result);
    free(result);
}
*/
