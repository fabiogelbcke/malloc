#include "malloc.h"

t_region *regions[3] = {NULL, NULL, NULL};

size_t get_region_size(int region_type, size_t size)
{
	size_t region_size;
	
	if (region_type == 0)
		region_size = TINY_REGION_PAGES * getpagesize();
	else if (region_type == 1)
		region_size = SMALL_REGION_PAGES * getpagesize();
	else
	{
		region_size = size;
		if (region_size % getpagesize() != 0)
			region_size = (region_size % getpagesize()) + getpagesize();
	}
	return region_size;
}

t_region *allocate_region(int region_type, size_t size)
{
	void *region_space;
	t_region *region;
	size_t region_size;

	region_size = get_region_size(region_type, size);
	region = mmap(0, region_size, PROT_READ | PROT_WRITE,
		 MAP_ANON | MAP_PRIVATE, -1, 0);
	region->size = region_size;
	region->blocks = (t_block*)(region + 1);
	region->next = NULL;
	region->prev = NULL;
	region->region_type = region_type;
	region->used = 0;
	return region;
}

t_block *has_enough_space(size_t size, int region_type){
	t_block *block;
	t_region *region;
	
	if (region_type == 2 || !regions[region_type])
		return (0);
	region = regions[region_type];
	while (region != NULL){
		block = region->blocks;
		while (block->next)
		{
			if (block->free == 1 && block->size >= size + sizeof(t_block))
				return (block);
			block = block->next;
		}
		if (get_region_size(region_type, size) > ((unsigned int)block - (unsigned int)block->region) + block->size + size + (2 * sizeof(t_block)))
			return (block);
		region = region->next;
	}
	return (NULL);
}

void *malloc(size_t size)
{
	int region_type;
	t_block *block;
	t_region *tmp;
	t_region *region;


	if (size == 0)
		return NULL;
	region_type = (size <= TINY_MAX_SIZE) ? 0 : 1;
	region_type = (size <= SMALL_MAX_SIZE) ? region_type : 2;
	block = has_enough_space(size, region_type);
	
	if (!block)
	{
		region = allocate_region(region_type, size);
		if (region == (void*) -1)
			return (NULL);
		block = region->blocks;
		block->region = region;
		block->prev = NULL;
		if (!regions[region_type])
			regions[region_type] = region;
		else
		{
			tmp = regions[region_type];
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = region;
			region->prev = tmp;
		}
	}
	else if (!block->next){
		block->next = (void*)block + block->size + sizeof(t_block);
		block->next->region = block->region;
		block->next->prev = block;
		block = block->next;
	}
	block->size = size;
	block->free = 0;
	block->next = NULL;
	block->region->used += size;
	block->check = (unsigned int)block % (block->region->size);
;
	return (void*)(block + 1);
}
