#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TARGET '\n'



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



char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (i <= start || len == 0)
		return (ft_strdup(""));
	if (len > (i - start))
		len = i - start;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	i = 0;
	while (str[start] && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	return (result);
}




char *ft_newline_search_plus(char **extra)
{
    long i;
    char *temp;
    char *temp2;

    i = 0;
        while((*extra)[i])
        {
         if((*extra)[i] == TARGET)
         {
            temp = ft_substr(*extra, 0, i + 1);
            temp2 = ft_substr(*extra, i + 1, ft_strlen(*extra));
            free(*extra);
            *extra = temp2;
            return(temp);
         }
            i++;
        }
        return(NULL);
}



int	main(void)
{
	char *str01 = NULL;
	char *str02 = NULL;
	char *extra = malloc(strlen("aaa10aaa20aaaaaa30aaaa40"));
	extra = strdup("aaa1\naaa2\naaaaa3\naaa4\n");
	while(extra && *extra)
	{
		printf("%s", ft_newline_search_plus(&extra));
		
		
	}

}
