#include "structures.h"
#include <ctype.h>

int hash(char const *key);
bool add_to_map(t_node *node, t_map *map);
bool delete_from_map(char const *key, t_map *map);
t_node *search_map(char const *key, t_map *map);
void print_map(t_map *map);

int hash(char const *key)
{
    int hash_value = 0, len = 0;
    while (*key != '\0')
    {
        len++;
        hash_value += tolower(*key) - 'a';
        hash_value *= len;
        key++;
    }
    return hash_value % MAP_SIZE;
}

bool add_to_map(t_node *node, t_map *map)
{
    if (node == NULL || map == NULL)
        return false;

    int key = hash(node->key);
    if (map->array[key] == NULL)
        map->array[key] = node;
    else
    {
        t_node *prev_node = map->array[key];
        while (prev_node->next != NULL)
            prev_node = prev_node->next;
        prev_node->next = node;
    }
    return true;
}

bool delete_from_map(char const *__key, t_map *map)
{
    if (__key == NULL || map == NULL)
        return false;

    int key = hash(__key);
    if (map->array[key] == NULL)
        return false; 
    
    t_node *prev_node = map->array[key];
    if(prev_node->key == __key)
        map->array[key] = prev_node->next;
    else
    {
        while (prev_node != NULL && prev_node->key != __key)
            prev_node = prev_node->next;
        if (prev_node == NULL)
            return false;
        prev_node->next = (prev_node->next)->next;
    }
    return true;
}

t_node *search_map(char const *__key, t_map *map)
{
    if (map == NULL)
        return (NULL);

    int key = hash(__key);
    
    t_node *node = map->array[key];
    while (node != NULL)
    {
        if (node->key == __key)
            return (node);
        node = node->next;
    }
    return (NULL);
}

void print_map(t_map *map)
{
    printf("--- start ---\n");
    
    for (int i=0; i < MAP_SIZE; i++)
    {
        printf("\t%d\t-\t\n", i);
        
        t_node *node = map->array[i];
        while (node != NULL)
        {
            printf("\t\t%s\t:\t%d\n", node->key, node->data);
            node = node->next;
        }
    }
    printf("--- end ---\n");
}
