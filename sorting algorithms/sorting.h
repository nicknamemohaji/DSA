#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef N
# define N 10000
#endif

#ifndef DEBUG
# define DEBUG 0
#endif

typedef struct s_count {
    int access;
    int write;
} t_count;


// O(n^2)
t_count insertion_sort(int , int []);
t_count selection_sort(int , int []);
t_count bubble_sort(int , int []);

// O(n lg n)
t_count quick_sort(int , int []);
t_count	merge_sort(int , int []);

// O(n)
t_count radix_sort(int , int []);
