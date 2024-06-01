
#include "block.h"

void block_split(BlockHeader *block, size_t size){
    if (block->size <= size + sizeof(BlockHeader))
        return;
    BlockHeader *new_block = (BlockHeader *)((char *)block + size + sizeof(BlockHeader));
    new_block->size = block->size - size - sizeof(BlockHeader);
    new_block->prev_size = size;
    new_block->is_allocated = false;
    new_block->is_first_block_in_arena = false;
    new_block->is_last_block_in_arena = block->is_last_block_in_arena;

    block->size = size;
    block->is_last_block_in_arena = false;
}

void block_merge(BlockHeader *block) {
    if (!block->is_last_block_in_arena && !block_next(block)->is_allocated) {
        // Об'єднання з наступним блоком
        BlockHeader *next_block = block_next(block);
        block->size += next_block->size + sizeof(BlockHeader);
        block->is_last_block_in_arena = next_block->is_last_block_in_arena;
    }
}


