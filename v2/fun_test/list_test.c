#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>



typedef struct s_list
{
    char        *content;
    struct s_list   *next;

}   t_list;



void ft_do(t_list **node, char  *str)
{
	*node = (*node)->next;
	*node = malloc(sizeof(t_list));
	if (*node == NULL)
		return ;

	(*node)->content = str;
	(*node)->next = NULL;
}

int main()
{
	t_list	*head;
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (0);

	char str01[] = "hello-";
	char str02[] = "world!-";

head = node;

node->content = str01;
node->next = NULL;
ft_do(&node, str02);

printf("%s%s\n", head->content, node->content);
} 
