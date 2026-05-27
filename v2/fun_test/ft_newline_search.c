#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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
	str[length + 1] = '\0';
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
	t_list *ptr2;

	if(*head == NULL)
			return ;
	ptr = *head;
	while(ptr != NULL)
	{
		if(ptr->content)
			free(ptr->content);
		ptr2 = ptr;
		ptr = ptr->next;
		free(ptr2);
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
//	printf("k:%zu, i:%zu\n", k ,i);
	if(k != i)
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
	}
    if(found == 1)
            return (1);

    return(-1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;

	if(str == NULL)
			return (i);
	while(str[i])
			i++;
	return(i);
}

void print_list(t_list *head)
{
    int i = 1;
    while (head)
    {
//      printf("link%d: %s\n", i, head->content);
		write(1, "link:", 5);
		if(head->content && i < 5)
			write(1, head->content, ft_strlen(head->content));
		 if (head->content == NULL)
            write(1, "(null)", 6);
        write(1, "\n", 1);
	
		head = head->next;
        i++;
    }

    write(1, "\n\n", 2);
}

int main(void)
{
	t_list 	*head = NULL;
	t_list *ptr;

	ptr = list_new();
	if (ptr == NULL)
			return(0);

	head = ptr;
	printf("string: [he\\nl---\\nlo\\noo \\nworld\\n]\n");
	
	ft_newline_search("he\nl---\nlo\noo \nworld\n", &head);

	print_list(ptr);
	
	head = ptr;
   	ft_list_clear(&head);



	ptr = list_new();
	if (ptr == NULL)
			return(0);

	head = ptr;	
	printf("string: [long way\\nfrom home\\npal]\n");
   	ft_newline_search("long way\nfrom home\npal", &head);
	print_list(ptr);
	head = ptr;
	ft_list_clear(&head);

	ptr = list_new();
	if (ptr == NULL)
			return(0);
	head = ptr;
	printf("string: [No newline here]\n");
    ft_newline_search("No newline here", &head);
    print_list(ptr);
    head = ptr;
    ft_list_clear(&head);

	ptr = list_new();
	if (ptr == NULL)
			return(0);
	head = ptr;
	printf("string:[abc\\ndef\\nghi]\n");
    ft_newline_search("abc\ndef\nghi", &head);
    print_list(ptr);
    head = ptr;
    ft_list_clear(&head);

	ptr = list_new();
	if (ptr == NULL)
		return(0);

head = ptr;
printf("string: []");
ft_newline_search("", &head);
print_list(ptr);
head = ptr;
ft_list_clear(&head);


//BREAK
	ptr = list_new();
	if (ptr == NULL)
		return(0);


head = ptr;
printf("string: [\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n]");


ft_newline_search("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", &head);
print_list(ptr);
head = ptr;
ft_list_clear(&head);

	ptr = list_new();
	if (ptr == NULL)
		return(0);


head = ptr;
printf("string: [\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n]");


ft_newline_search("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", &head);
print_list(ptr);
head = ptr;
ft_list_clear(&head);
    return 0;
	
	
	ptr = list_new();
	if (ptr == NULL)
		return(0);


head = ptr;
printf("string: [\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n\\n]");


ft_newline_search("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", &head);
print_list(ptr);
head = ptr;
ft_list_clear(&head);
    return 0;


}

