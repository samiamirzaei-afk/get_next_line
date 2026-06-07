*This project has been created as part of the 42 curriculum by ammirzae.*

# Get Next Line – Because reading a line from a file is way too tedious

## Description

`get_next_line` funtion returns first line from the givene file descriptor.  
A “line” for this function is a block of text that ends with a newline symbol “\n”. If newline is not found, then the function will just print everything until the end of the file.
The goal of this project is to learn about static varibles.  
The function works with a macro called `BUFFER_SIZE` that can also be changed during complilation, you can change it simply by adding `-D BUFFER_SIZE=n` and changing 'n' to any number you like (default is 42).    
`BUFFER_SIZE` is used to determine the ammount of bytes the function `read` is allowed to read after each call.
if no newline was found in the buffer size, it will be saved in the heap with `malloc` and joined back to the new buffer.  
```c
char *get_next_line(int fd);
```
**BE CAREFUL**  
● If `BUFFER_SIZE` is changed to a big number, it will be larger than the stack and cause problems, ususally a SEGFAULT. so keep it less than 5'000.  
● If the function stops being called before reading the end of the file, there might still be information inside saved in the heap, give `get_next_line(-n)`("-n" being any negative number) to free whatever is left inside.  

## Instructions
simply add the header `get_next_line.h` at the top of your C file, and then add `get_next_line.c` `get_next_line_utils.c` while you are compiling your program. (make sure that all these files are in the same folder as your program)

```bash
cc  your_program.c  get_next_line.c get_next_line_utils.c 
```
a Makefile was not allowed to be submitted for this project but I have provided one inside the readme:

```Makefile
BUG_NAME = a.bug
LIB_NAME = libgnl.a

CFLAGS = -Wall -Wextra

SRC = get_next_line_utils.c\
          get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
        $(AR) -rcs $@ $?

clean:
        $(RM) $(OBJ)

fclean:
        $(RM) $(LIB_NAME) $(BUG_NAME)

bug: 
        $(CC) $(CFLAGS)  $(SRC) -o $(BUG_NAME) -g

.PHONY: bug all clean fclean
```
use `make` to make a libary, that way you would only need to add the libary and the header during complilation:

```bash
cc  -I/path/to/get_next_line.h your_program.c -L/path/to/libgnl.a -lgnl
```
(as stated above, if `get_next_line.h` is in the same directory, then the compiler will add it automatically)

### Resources
- [42 Norm] – Coding standard for 42 projects
- [get_next_line explained] (https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUNZ2V0X25leHRfbGluZQ%3D%3D) – A video that explaining this topic

### AI usage
During this project, AI (primarily DeepSeek) was used for the following tasks:
- Help with correcting mistakes and better formating the code (varibale names).
AI did not provide complete function implementations; it was used as a complementary learning tool.

