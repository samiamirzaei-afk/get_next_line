*This project has been created as part of the 42 curriculum by ammirzae.*

# Get Next Line – Because reading a line from a file is way too tedious

## Description

`get_next_line` is a funtion that takes a file descriptor and reads the first line from it.
A “line” for this function is a block of text that ends with a newline symbol “\n”. if no newline is found then the function will just print everything until the end of the file.
The goal of this project is to learn about static varibles and thus their use is needed for this project.

```c
char *ft_printf(int fd);
```

## Instructions
simply add the header `get_next_line.h` at the top of your C file, and then add `get_next_line.c` `get_next_line_utils.c` while you are compiling your program. (make sure that all these files are in the same folder as your main program)

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
use `make` to make a libary, that way you would only need to ad the libary and the header during complilation:

```bash
cc  -I/path/to/libft.h your_program.c -L/path/to/libft.a -lgnl
```
(as stated above, if `get_next_line.h` is in the same directory, then the compiler will add it automatically)

- [42 Norm] – Coding standard for 42 projects
-[get_next_line explained] (https://www.youtube.com/watch?v=8E9siq7apUU&pp=ygUNZ2V0X25leHRfbGluZQ%3D%3D) – A video that explaining this topic

### AI usage
During this project, AI (primarily DeepSeek) was used for the following tasks:
- Help with correcting mistakes and better formating the code (varibale names).
AI did not provide complete function implementations; it was used as a complementary learning tool.

