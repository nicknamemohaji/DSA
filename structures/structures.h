#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifndef COUNT
# define COUNT 10
#endif

typedef struct s_node {
    int data;
    struct s_node *next;
} t_node;

typedef struct s_list {
    t_node *head;
} t_list;

typedef struct s_stack {
    int size;
    t_node *head;
    t_node *tail;
} t_stack;


// linked_list.c
t_node *new_node(int data);
t_node *search_list(int data, t_list *list);
bool add_node_to_list(t_node *new, t_list *list);
bool delete_from_list(t_node *node, t_list *list);
void print_list(t_list *list);

// stack.c
t_node *stack_top(t_stack *stack);
bool stack_push(t_node *node, t_stack *stack);
t_node *stack_pop(t_stack *stack);
void print_stack(t_stack *stack);
