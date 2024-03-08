NAME = structures
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -g -I .

DEFINES = 
ifdef COUNT
	DEFINES += -D COUNT=$(COUNT)
endif
ifdef DEBUG
	DEFINES += -D DEBUG=$(DEBUG)
endif

SOURCES = 	main.c \
			linked_list/node.c \
			linked_list/linked_list.c \
			linked_list/linked_list_test.c \
			stack/stack.c \
			stack/stack_test.c \
			queue/queue.c \
			queue/queue_test.c \
			map/maps.c \
			map/map_test.c \
			tree/binary_tree.c \
			tree/tree_traversal.c \
			tree/tree_test.c
			
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(DEFINES)


clean:
	@rm -f $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(DEFINES)

PHONY: .test .clean