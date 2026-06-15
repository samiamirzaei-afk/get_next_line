*This project has been created as part of the 42 curriculum by ammirzae.*

# Get Next Line – Because reading a line from a file is way too tedious

## Description

`get_next_line` function returns first line from the given file descriptor.  
A “line” for this function is a block of text that ends with a newline symbol “\n”. If newline is not found, then the function will just print everything until the end of the file. you can also change what simply you want each line to end by adding with `-D TARGET=\'n\'` and swap 'n' with any letter you want.  

The goal of this project is to learn about static varibles.  
The function works with a macro called `BUFFER_SIZE` that can also be changed during compilation, you can change it simply by adding `-D BUFFER_SIZE=n` and changing 'n' to any number you like (default is 42).    
`BUFFER_SIZE` is used to determine the amount of bytes the function `read` is allowed to read after each call.
if no newline was found in the buffer size, it will be saved in the heap with `malloc` and joined back to the new buffer.  
```c
char *get_next_line(int fd);
```
**BE CAREFUL**  
● If `BUFFER_SIZE` is changed to a big number, it will be larger than the stack and cause problems, usually a SEGFAULT. so keep it less than 5'000.  
● If the function stops being called before reading the end of the file, there might still be information inside saved in the heap, give `get_next_line(-n)`("-n" being any negative number) to free whatever is left inside.  

## Instructions
simply add the header `get_next_line.h` at the top of your C file, and then add `get_next_line.c` `get_next_line_utils.c` while you are compiling your program. (make sure that all these files are in the same folder as your program)

```bash
cc  your_program.c  get_next_line.c get_next_line_utils.c 
```
a Makefile was not allowed to be submitted for this project but I have provided a simple one inside the readme:

```Makefile
BUG_NAME = a.bug
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line_utils.c\
	  get_next_line.c\
	  your_program.c

bug: 
	$(CC) $(CFLAGS)  $(SRC) -o $(BUG_NAME) -g

.PHONY: bug
```
Simply write `make` in the terminal and a simple executable will be created. (make sure to change `your_program.c` to whatever your main file is called).


### Resources
- [42 Norm] – Coding standard for 42 projects
- [get_next_line explained] (https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUNZ2V0X25leHRfbGluZQ%3D%3D) – A video that explaining this topic

### AI usage
During this project, AI (primarily DeepSeek) was used for the following tasks:
- Help with correcting mistakes and better formating the code (variable names).
AI did not provide complete function implementations; it was used as a complementary learning tool.

