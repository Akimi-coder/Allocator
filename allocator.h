#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>
#include "block.h"
#include "config.h"
#include "kernel.h"

void *mem_alloc(size_t size);
void *mem_free(void *block);
void *mem_realloc(void *block, size_t size);
void mem_show();

#endif /* ALLOCATOR_H */