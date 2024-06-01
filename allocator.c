#include "allocator.h"


BlockHeader *head = NULL;

BlockHeader* get_free_block(size_t size){
    BlockHeader *block = head;
   while (block)
    {
      if(block_get_size(block) == 0){
        return block;
      }
      if(!block_is_allocated(block) && block_get_size(block) >= size) {
        return block;
      }  
      block = block_next(block);
    }

}

void *mem_alloc(size_t size) {
    void *space;
    BlockHeader *block;

    block = get_free_block(size);
    if(block){
      block->is_allocated = 1;
      block->size = size;
      return block_to_payload(block);
    }
    space = get_memory(sizeof(BlockHeader) + DEFAULT_ARENA_SIZE);
    if(space == NULL){
      return NULL;
    }

    block = space;
    block_set_size(block,size);
    block_set_first_block(block,1);
    block_set_allocated(block,1);
    if(!head){
      head = block;
    }
    return block_to_payload(block);

}

void mem_show() {
     BlockHeader *block = (BlockHeader *)head;

    while ((char *)block < head + DEFAULT_ARENA_SIZE) {
      if(block->size > 0){
              printf("Block at %p, size %zu, allocated: %s\n", block, block_get_size(block), block_is_allocated(block) ? "yes" : "no");
      }
      block = block_next(block);
    }
}

void *mem_free(void *block){
  BlockHeader *del = (BlockHeader *)block - 1;
  del->is_allocated = false;
}

void *mem_realloc(void *block, size_t size){
    BlockHeader *header;
    void *ret;
    if(!block || !size){
      return mem_alloc(size);
    }
    header = (BlockHeader*)block - 1;
    if (header->size >= size){
      return block;
    }
    ret = mem_alloc(size);
    if(ret){
      memcpy(ret,block,header->size);
      mem_free(block);
    }
    return ret;

}

