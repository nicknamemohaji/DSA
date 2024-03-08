#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#ifndef COUNT
# define COUNT 10
#endif
#ifndef MAP_SIZE
# define MAP_SIZE 5
#endif

/**************************************
* data types
**************************************/
// linked list
typedef struct s_node {
    struct s_node *next;
    void *data_ptr; 
    int data;
} t_node;

typedef struct s_list {
    t_node *head;
} t_list;

// stack
// (note that stack is implemented with linked list)
typedef struct s_stack {
    int size;
    t_node *head;
    t_node *tail;
} t_stack;

// queue
typedef struct s_queue {
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_queue;

// tree
typedef struct s_tree {
    t_node *node;
    struct s_tree *left;
    struct s_tree *right;
} t_tree;

// queue
typedef struct s_map {
    t_node *array[MAP_SIZE];
} t_map;

/**************************************
* implementations
**************************************/
/* 
linked list
*/
// linked_list.c
t_node *search_list(int data, t_list *list);
bool add_node_to_list(t_node *new_node, t_list *list);
bool delete_from_list(t_node *node, t_list *list);
void print_list(t_list *list);
// node.c
t_node *new_node(int data);
// test_linked_list.c
void test_linked_list(t_node *nodes[COUNT]);

/*
stack
*/ 
// stack.c
t_node *stack_top(t_stack *stack);
bool stack_push(t_node *node, t_stack *stack);
t_node *stack_pop(t_stack *stack);
void print_stack(t_stack *stack);
// stack_test.c
void test_stack(t_node *nodes[COUNT]);

/*
trees
*/
// binary_tree.c
bool add_to_tree(t_node *node, t_tree *tree);
bool delete_from_btree(t_node *node, t_tree *tree);
void print_tree(t_tree *tree);
void free_tree(t_tree *tree);
// tree_traversal.c
t_node *tree_search_preorder(int data, t_tree *tree);
t_node *tree_search_postorder(int data, t_tree *tree);
t_node *tree_search_inorder(int data, t_tree *tree);
t_node *btree_search(int data, t_tree *tree);
// tree_test.c
void test_tree(t_node *nodes[COUNT]);

/*
queue
*/
// queue.c
bool enqueue(t_node *node, t_queue *queue);
t_node *dequeue(t_queue *queue);
void print_queue(t_queue *queue);
// queue_test.c
void test_queue(t_node *nodes[COUNT]);

/*
hashmap
*/
// maps.c
int hash(char const *key);
bool add_to_map(t_node *node, t_map *map);
bool delete_from_map(char const *key, t_map *map);
t_node *search_map(char const *key, t_map *map);
void print_map(t_map *map);
// map_test.c
void test_map(t_node *nodes[COUNT]);
