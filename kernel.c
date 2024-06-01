#include "kernel.h"

void *get_memory(size_t size) {
    return malloc(size);
}