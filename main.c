#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "allocator.h"


void fill_block(void *ptr, size_t size) {
    unsigned int *data = (unsigned int *)ptr;
    for (size_t i = 0; i < size / sizeof(unsigned int); ++i) {
        data[i] = rand();
    }
}

int main() {

    int *ptr = (int*)mem_alloc(10 * sizeof(int));
    int *ptr1 = (int*)mem_alloc(10 * sizeof(int));
    int *ptr2 = (int*)mem_alloc(10 * sizeof(int));

    ptr[0] = 1;
    ptr[1] = 2;
    ptr[2] = 3;
    ptr[3] = 4;
    ptr[4] = 5;
    ptr[5] = 6;
    ptr[6] = 7;
    ptr[7] = 8;
    ptr[8] = 9;
    ptr[9] = 10;

    ptr1[0] = 1;
    ptr1[1] = 1;
    ptr1[2] = 1;
    ptr1[3] = 1;
    ptr1[4] = 5;
    ptr1[5] = 6;
    ptr1[6] = 7;
    ptr1[7] = 8;
    ptr1[8] = 9;
    ptr1[9] = 10;

    ptr2[0] = 10;

    mem_show();
    
    ptr = mem_realloc(ptr,15 * sizeof(int));
    for (int i = 9; i < 15; i++) {
        ptr[i] = i + 1;
    }
    
    printf("--------------------------\n");
    mem_show();

    mem_free(ptr);
    mem_free(ptr1);
    mem_free(ptr2);

    printf("--------------------------\n");
    mem_show();
    

    return 0;
}