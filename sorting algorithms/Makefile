NAME = compare_sorting
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=address -g -I .

DEFINES = 
ifdef N
	DEFINES += -D N=$(N)
endif
ifdef DEBUG
	DEFINES += -D DEBUG=$(DEBUG)
endif

SOURCES = 	O_n_2/bubble.c \
			O_n_2/insertion.c \
			O_n_2/selection.c \
			O_n_lg_n/merge.c \
			O_n_lg_n/qsort.c \
			O_n/radix_lsd.c \
			O_n/counting.c \
			main.c
OBJECTS = $(SOURCES:.c=.o)

test: clean $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(DEFINES)


clean:
	@rm -f $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(DEFINES)

PHONY: .test .clean