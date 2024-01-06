#include<stdio.h>

typedef struct Rope {
    struct Rope *left;
    struct Rope *right;
    int size;  
    const char *val;
} Rope;  
  
int main() {  
    Rope l;  
    l.size=10;  
    l.val = "left";
    Rope r;  
    r.size=10;  
    r.val = "left";
      
    Rope head;  
    head.size = 10;
    head.left = &l;
    head.right = &r;
    return 0; 
}
