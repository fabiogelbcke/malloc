#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
	t_block *newblock;
	t_block *block;
	
	if (!ptr)
		return (malloc(size));
	block = (t_block*)ptr - 1;
	if (!block_exists(block))
	{
		ft_putstr("Realloc: Invalid block\n");
		return (NULL);
	}
	if (block->free)
		return (malloc(size));
	if (!block->next
		&& (unsigned int)block + size + sizeof(t_block) < (unsigned int)block->region->blocks + block->region->size)
	{
		block->region->used += size - block->size;
		block->size = size;
		return (block + 1);
	}
	else if (block->next && block->next->free
			 && block->size + sizeof(t_block) + block->next->size >= size)
	{
		block->region->used += size - block->size;
		block->size = size;
		block->next = block->next->next;
		return (block + 1);
	}
	else
	{
		newblock = (t_block*)malloc(size);
		if (!newblock)
			return (NULL);
		ft_memcpy(newblock, ptr, block->size);
		free(ptr);
		return (newblock);
	}
}
