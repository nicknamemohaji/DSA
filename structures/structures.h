#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifndef COUNT
# define COUNT 10
#endif

/*
node.c
*/
typedef struct s_node {
    int data;
    struct s_node *next;
    char *key;  // for map
} t_node;
t_node *new_node(int data);

/*
linked_list.c
*/
typedef struct s_list {
    t_node *head;
} t_list;

t_node *search_list(int data, t_list *list);
bool add_node_to_list(t_node *new_node, t_list *list);
bool delete_from_list(t_node *node, t_list *list);
void print_list(t_list *list);

/*
stack.c
*/ 
typedef struct s_stack {
    int size;
    t_node *head;
    t_node *tail;
} t_stack;

t_node *stack_top(t_stack *stack);
bool stack_push(t_node *node, t_stack *stack);
t_node *stack_pop(t_stack *stack);
void print_stack(t_stack *stack);

/*
binary_tree.c
*/
typedef struct s_tree {
    t_node *node;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

bool add_to_tree(t_node *node, t_tree *tree);
t_node *search_from_tree(int data, t_tree *tree);
bool delete_from_tree(t_node *node, t_tree *tree);
void print_tree(t_tree *tree);

/*
queue.c
*/
typedef struct s_queue {
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_queue;

bool add_to_queue(t_node *node, t_queue *queue);
t_node *pop_queue(t_queue *queue);
void print_queue(t_queue *queue);

/*
maps.c
*/
#ifndef MAP_SIZE
# define MAP_SIZE 5
#endif
typedef struct s_map {
    t_node *array[MAP_SIZE];
} t_map;

int hash(char const *key);
bool add_to_map(t_node *node, t_map *map);
bool delete_from_map(char const *key, t_map *map);
t_node *search_map(char const *key, t_map *map);
void print_map(t_map *map);
