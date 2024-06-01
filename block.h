#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdbool.h>


typedef struct BlockHeader {
    size_t size;                    // Розмір поточного блоку
    size_t prev_size;               // Розмір попереднього блоку
    bool is_allocated;              // Прапорець «блок зайнятий»
    bool is_first_block_in_arena;   // Прапорець «перший блок в арені»
    bool is_last_block_in_arena;    // Прапорець «останній блок в арені»
} BlockHeader;


// Функції для поділу та об'єднання блоків
void block_split(BlockHeader *block, size_t size);
void block_merge(BlockHeader *block);

// Inline функції та setter'и та getter'и
static inline void *block_to_payload(BlockHeader *block) {
    return (void *)(block + 1);
}

static inline BlockHeader *payload_to_block(void *payload) {
    return ((BlockHeader *)payload) - 1;
}

static inline BlockHeader *block_next(BlockHeader *block) {
    return (BlockHeader *)((char *)block + block->size + sizeof(BlockHeader));
}

static inline BlockHeader *block_prev(BlockHeader *block) {
    return (BlockHeader *)((char *)block - block->prev_size - sizeof(BlockHeader));
}

// Setter'и та getter'и
static inline size_t block_get_size(BlockHeader *block) {
    return block->size;
}

static inline void block_set_size(BlockHeader *block, size_t size) {
    block->size = size;
}

static inline size_t block_get_prev_size(BlockHeader *block) {
    return block->prev_size;
}

static inline void block_set_prev_size(BlockHeader *block, size_t prev_size) {
    block->prev_size = prev_size;
}

static inline bool block_is_allocated(BlockHeader *block) {
    return block->is_allocated;
}

static inline void block_set_allocated(BlockHeader *block, bool is_allocated) {
    block->is_allocated = is_allocated;
}

static inline bool block_is_first_block(BlockHeader *block) {
    return block->is_first_block_in_arena;
}

static inline void block_set_first_block(BlockHeader *block, bool is_first_block) {
    block->is_first_block_in_arena = is_first_block;
}

static inline bool block_is_last_block(BlockHeader *block) {
    return block->is_last_block_in_arena;
}

static inline void block_set_last_block(BlockHeader *block, bool is_last_block) {
    block->is_last_block_in_arena = is_last_block;
}


#endif /* BLOCK_H */