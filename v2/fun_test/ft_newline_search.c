#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct s_list
{
	char		*content;
	struct s_list	*next;

}	t_list;


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
	str = malloc((length + 2) * sizeof(char));
	if(str == NULL)
	{
		printf("MALLOC FAIL at ft_cat_str\n");
			return(NULL);

	}
	str[length] = '\0';
	while(i <= length)
	{
		str[i] = read_buffer[i];
		i++;
	}
	return(str);
}
/*	* * * HELPER * * * 	*/

void ft_list_clear(t_list **head)
{
	t_list *ptr;

	if(*head == NULL)
			return ;
	ptr = *head;
	while(ptr != NULL)
	{
		free((*head)->content);
		ptr = (*head)->next;
		free(*head);
	}
}

int ft_newline_search(char *buffer, t_list **head)
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
            str = ft_cat_str(&buffer[k], (i - k));
            if(str == NULL)
            {
                    printf("MALLOC FAIL at ft_newline_search (ft_cat_str)\n");
                    return(-1);
            }
            (*head)->content = str;
            (*head)->next = list_new();
			(*head) = (*head)->next;
            if(*head == NULL)
            {
                    printf("MALLOC FAIL at ft_newline_search (list_new)\n");
                    return(-1);
            }
                k = i + 1;
                found = 1;
        }
        i++;
    }
    if(found == 1)
            return (1);

    return(-1);
}

void print_list(t_list *head)
{
    int i = 1;
    while (head)
    {
        printf("link%d: %s", i, head->content);
        head = head->next;
        i++;
    }
}

int main(void)
{
    t_list 	*head = NULL;
	t_list *ptr;


	head = malloc(sizeof(t_list));
	if (head == NULL)
			return(0);

	ptr = head;
    // Test 1: BUFFER_SIZE = 4, string = "hellooo world\n"
    ft_newline_search("he\nl   \nlo\noo \nworld\n", &head);
    print_list(ptr);
	*head = *ptr;
    ft_list_clear(&head);
	return (0);
    /*
	
	//REPLACE_NEW

    // Test 2: BUFFER_SIZE = 10, string = "long way\nfrom home\npal"
    ft_newline_search("long way\nfrom home\npal", &head);
    print_list(head);
    ft_list_clear(REPLACE_CLEAR);
    //REPLACE_NEW

    // Additional test: string with no newline, BUFFER_SIZE = 5 (example)
    ft_newline_search("No newline here", &head);
    print_list(head);
    ft_list_clear(REPLACE_CLEAR);
    //REPLACE_NEW

    // Test with multiple newlines and exact buffer boundary
    ft_newline_search("abc\ndef\nghi", &head);
    print_list(head);
    ft_list_clear(REPLACE_CLEAR);
    //REPLACE_NEW

    return 0;

*/
}

