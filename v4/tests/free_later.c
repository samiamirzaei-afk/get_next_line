#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char *str = strdup("this is a goffy string");

	printf("%c\n", str[0]);
	str += 5;
	printf("%c\n", str[0]);
	free (str);

}

