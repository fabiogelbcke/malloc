#include "malloc.h"

int block_checks(t_block *block, t_region *region)
{
	return (((unsigned int)block % region->size) == block->check);
}

int block_exists(t_block *block)
{
	t_region *region;

	region = regions[0];
	while (region)
	{
		if ((size_t)block >= (size_t)region->blocks && (size_t)block <= (size_t)region->blocks + region->size)
			return (block_checks(block, region));
		region = region->next;
	}
	region = regions[1];
	while (region)
	{
		if (block >= region->blocks && block <= region->blocks + (region->size/sizeof(t_block)))
			return (block_checks(block, region));
		region = region->next;
	}
	region = regions[2];
	while (region)
	{
		if (block == region->blocks)
			return (1);
		region = region->next;
	}
	return (0);
}

void defragment_free_blocks(t_block *block)
{
	while (block->prev && block->prev->free)
		block = block->prev;
	while (block->next && block->next->free)
	{
		block->size += block->next->size + sizeof(t_block);
		block->next = block->next->next;
	}
}

void free(void *ptr)
{
	t_block *block;
	t_region *region;

	if (!ptr)
		return;
	block = (t_block*)ptr - 1;
	if (!block_exists(block))
	{
		ft_putstr("Free: Invalid block\n");
		return;
	}
	if (block->free == 1)
	{
		ft_putstr("Block has already been freed\n");
		return;
	}
	block->free = 1;
	region = block->region;
	region->used -= block->size;
	if (region->used == 0){
		if (region->prev)
			region->prev = region->next;
		else
			regions[region->region_type] = region->next;
		munmap(region, region->size);
	}
	else
		defragment_free_blocks(block);
}
