#include "rope.h"
#include <stdlib.h>

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
    traverse_dfs_post(head, print_rope);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    // free 
    traverse_dfs_post(head, destroy_rope);
    free(head);
    fclose(fptr);
    
    return 0; 
}
