#include<stdio.h>
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

typedef struct Rope {
    struct Rope *left;
    struct Rope *right;
    size_t l_size;  
    char *content;
} Rope;  

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

typedef void (*Operation)(Rope*);

void traverse_dfs_in(Rope* head, Operation op) {
   if (head->left) traverse_dfs_in(head->left, op);
   op(head);
   if (head->right) traverse_dfs_in(head->right, op);
}

void destroy_rope(Rope* head) {
    free(head->content);
    if (head->left) {
        traverse_dfs_in(head->left, destroy_rope);
        free(head->left);
    }
    if (head->right) {
        traverse_dfs_in(head->right, destroy_rope);
        free(head->right);
    }
    /* free(head); */
}

void print_rope(Rope* head) {
    if(head->content) printf("%s", head->content);
}
  
int main(void) {  
    const char* filename = "t8.shakespeare.txt";
    FILE *fptr = fopen(filename, "rb");
    if (!fptr) {
        printf("[E] couldnt open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // calculate the size of the buffer
    fseek(fptr, 0L, SEEK_END);
    long buf_size = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    Rope *head = create_rope(fptr, 0, buf_size-1);

    // print the rope
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BEGIN ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    traverse_dfs_in(head, print_rope);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    // free 
    /* traverse_dfs_in(head, destroy_rope); */
    fclose(fptr);
    
    return 0; 
}
