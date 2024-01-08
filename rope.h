#include <stdio.h>

#ifndef ROPE_H_
#define ROPE_H_

typedef struct Rope {
    struct Rope *left;
    struct Rope *right;
    size_t l_size;  
    char *content;
} Rope;  

Rope* create_rope(FILE*, int, int);

typedef void (*Operation)(Rope*);
void traverse_dfs_in(Rope*, Operation);

void destroy_rope(Rope*); 
void print_rope(Rope*);

#endif // ROPE_H_
