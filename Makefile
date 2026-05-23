BUG_NAME = a.bug
CFLAGS = -Wall -Wextra

SRC = get_next_line_utils.c\
	  get_next_line.c

bug: 
	$(CC) $(CFLAGS)  $(SRC) -o $(BUG_NAME) -g

.PHONY: bug
