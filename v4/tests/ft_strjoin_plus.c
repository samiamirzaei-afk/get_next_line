#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void ft_strcopy(char *result, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        result[i] = str[i];
        i++;
    }
}

char    *ft_strjoin(char **str1, char **str2)
{
    int     len1;
    int     len2;
    char    *result;


    len1 = 0;
    len2 = 0;
    if (*str1 != NULL && *str1)
    {
        len1 = strlen(*str1);
    }
    if(*str2 != NULL && *str2)
        len2 = strlen(*str2);
    result = malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    result[len1 + len2] = '\0';
	if(len1 != 0)
	{
    	ft_strcopy(&result[0], *str1);
	      free(*str1);
	}
	if(len2 != 0)
    ft_strcopy(&result[len1], *str2);
    return (result);
}


int	main(void)
{
	char *str01 = NULL;
	char *str02 = NULL;
	char *str03 = "hello";
	char *str04 = "world";
	char *str05 = strdup("long boi string-");
	char *str06 = "sort b str";
	char *result;
	
//	printf("NULL + NULL: %s\n", (result=ft_strjoin(&str01, &str02)));
	printf("longboi string- + hello : %s\n", (result=ft_strjoin(&str05, &str03)));
	free(result);
	return(0);
	printf("NULL + 'hello': %s\n", ft_strjoin(&str01, &str03));
	printf("'hello' + NULL: %s\n", ft_strjoin(&str03, &str02));
	printf("'hello' + 'world': %s\n", ft_strjoin(&str03, &str04));
	printf("'long boi string-' + 'sort b str': %s\n", ft_strjoin(&str05, &str06));


}
