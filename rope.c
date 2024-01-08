
#include "rope.h"
#include <stdlib.h>

/*
 * Ropes
 * =====
 * TODO
 * [X] Convert to rope
 * [ ] Rebalancing Algo
 * [ ] Operations
 *      [ ] Insertion/Deletion at i
 *      [ ] Concatenate
 *      [X] Iteration
 *      [ ] Find the ith letter
 * [ ] Comparison to char arr
 * [ ] Visualization etc
 */

#define MAX_LEAF_SIZE 5

Rope* create_rope(FILE *fptr, int beg, int end) {
    Rope* head = (Rope*)malloc(sizeof(Rope));
    if (end-beg+1 > MAX_LEAF_SIZE) {
        head->l_size =  (end-beg+1)/2;
        head->content = NULL;
        head->left = create_rope(fptr, beg, beg+(end-beg)/2);
        head->right = create_rope(fptr, beg+(end-beg)/2+1, end);
    }
    else {
        head->l_size = end-beg+1;
        head->content = (char*)malloc(sizeof(char)*head->l_size);
        fread(head->content, sizeof(*head->content), head->l_size, fptr);
        // printf("adding to the tree from %d to %d i.e. |%s|\n", beg, end, head->content);
    }
    // logic
    return head;
}

void traverse_dfs_in(Rope* head, Operation op) {
   if (!head) return ; 
   if (head->left) traverse_dfs_in(head->left, op);
   if (head->right) traverse_dfs_in(head->right, op);
   op(head);
}

void destroy_rope(Rope* head) {
    free(head->content);
    free(head->left);
    free(head->right);
    /* free(head); */
}

void print_rope(Rope* head) {
    if(head->content) printf("%s", head->content);
}
  
