NAME = structures
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -g -I .

DEFINES = 
ifdef COUNT
	DEFINES += -D COUNT=$(COUNT)
endif
SOURCES = 	linked_list.c \
			stack.c \
			main.c
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(DEFINES)


clean:
	@rm -f $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(DEFINES)

PHONY: .test .clean