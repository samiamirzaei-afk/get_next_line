#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 45

void	call_again(void)
{
	static int line;

	line = 0;
	printf("Line: %d:", line);
	++line;	
}


int main(int argc, char **argv) 
{
	int i;
	size_t count;
	int fd;
	char buff[BUFFER_SIZE];
	
	i = 1;
	fd = open(argv[1], O_RDONLY);
	while(i < 20)
	{
		call_again();
		count = read(fd, buff, BUFFER_SIZE);
		write(1, &buff, count);
		i++;
	}
}
